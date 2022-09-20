package main

import (
	"fmt"

	"github.com/ishangoyal13/todoList/models"
	"github.com/ishangoyal13/todoList/routers"
)

func main() {
	r := routers.RegisterRoutes()
	models.ConnectDatabase()

	fmt.Println("Successfully connected")
	r.Run(":8080")
}
