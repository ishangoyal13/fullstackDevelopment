package models

import (
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Todo struct {
	ID   uint    `gorm:"primary key:autoIncrement" json:"id"`
	Todo *string `json:"todo"`
}

var DB *gorm.DB

func ConnectDatabase() {
	db, err := gorm.Open(postgres.New(postgres.Config{
		DSN: "host=localhost user=postgres dbname=todo password=admin sslmode=disable",
	}))
	if err != nil {
		panic("Error:Failed to connect to database!")
	}
	// db.Exec(`CREATE DATABASE todo`)

	db.AutoMigrate(&Todo{})

	DB = db
}
