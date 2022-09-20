package models

import (
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Key struct {
	ID      uint    `gorm:"primary key:autoIncrement" json:"id"`
	Keyword *string `json:"keyword"`
}

var DB *gorm.DB

func ConnectDatabase() {
	db, err := gorm.Open(postgres.New(postgres.Config{
		DSN: "host=localhost user=postgres dbname=dummydb password=admin sslmode=disable",
	}))
	if err != nil {
		panic("Error:Failed to connect to database!")
	}

	db.AutoMigrate(&Key{})

	DB = db
}
