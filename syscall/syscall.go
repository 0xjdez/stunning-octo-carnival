package main

import (
	"io"
	"os"
)

func main() {
	file, err := os.OpenFile("foo", os.O_CREATE|os.O_RDWR|os.O_APPEND, 420)
	if err != nil {
		panic(err)
	}

	defer file.Close()
	io.WriteString(file, "Hello, World\n")

}
