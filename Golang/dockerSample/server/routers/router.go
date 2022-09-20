package routers

import (
	"net/http"

	"github.com/ishangoyal13/dockerEx/models"

	"github.com/ishangoyal13/dockerEx/middleware"

	"github.com/gin-gonic/gin"
)

type CreateDataInput struct {
	Keyword string `json:"keyword"`
}

func RegisterRoutes() *gin.Engine {
	router := gin.Default()
	router.Use(middleware.CORSMiddleware())

	router.POST("/keydata", postData)

	return router
}

func postData(c *gin.Context) {
	var newkeyword CreateDataInput
	if err := c.ShouldBindJSON(&newkeyword); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	dbReq := newkeyword.Keyword
	kw := models.Key{Keyword: &newkeyword.Keyword}
	models.DB.Create(&kw)

	var allKeys []models.Key
	models.DB.Where("keyword = ?", dbReq).Find(&allKeys)

	c.IndentedJSON(http.StatusOK, gin.H{"dbdata": allKeys})
}
