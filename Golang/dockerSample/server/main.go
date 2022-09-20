package main

import (
	"fmt"
	"os"

	"github.com/ishangoyal13/dockerEx/models"
	"github.com/ishangoyal13/dockerEx/routers"
)

func main() {
	r := routers.RegisterRoutes()
	models.ConnectDatabase()

	r.Static("/", "./build")

	fmt.Println("Successfully connected")
	port := os.Getenv("PORT")
	//defaultPort := "8080"
	r.Run(":" + port)
}
