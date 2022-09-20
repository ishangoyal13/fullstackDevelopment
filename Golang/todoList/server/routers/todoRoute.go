package routers

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/ishangoyal13/todoList/middleware"
	"github.com/ishangoyal13/todoList/models"
)

type CreateTodo struct {
	Todo string `json:"todo"`
}

func RegisterRoutes() *gin.Engine {
	router := gin.Default()
	router.Use(middleware.CORSMiddleware())

	router.GET("/todo", getTodo)
	router.POST("/todo", postTodo)
	router.PUT("/todo/:id", updateTodo)
	router.DELETE("/todo/:id", deleteTodo)

	return router
}

func getTodo(c *gin.Context) {
	var allTodos []models.Todo
	models.DB.Find(&allTodos)

	c.IndentedJSON(http.StatusOK, gin.H{"todolist": allTodos})
}
func postTodo(c *gin.Context) {
	var newtodo CreateTodo
	if err := c.ShouldBindJSON(&newtodo); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}
	listItem := models.Todo{Todo: &newtodo.Todo}
	models.DB.Create(&listItem)

	getTodo(c)
}

func updateTodo(c *gin.Context) {
	var update CreateTodo
	var database models.Todo
	if err := c.ShouldBindJSON(&update); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}
	if err := models.DB.Model(&database).Where("id = ?", c.Param("id")).Update("todo", &update.Todo).Error; err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": "Record not found!"})
		return
	}
	getTodo(c)
}

func deleteTodo(c *gin.Context) {
	var delTodo models.Todo
	if err := models.DB.Where("id = ?", c.Param("id")).First(&delTodo).Error; err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": "Record not found!"})
		return
	}

	models.DB.Delete(&delTodo)

	getTodo(c)
}
