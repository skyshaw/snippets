package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
)

type folder struct {
	Id   string
	Name string
}

func auth() (id string, name string) {
	const cfgFile = ".boxrc"
	var apiKey, authToken string
	file, err := os.Open(cfgFile)
	if err != nil {
		log.Fatalln(err)
	}
	defer file.Close()
	if _, err := fmt.Fscanf(file, "%s %s", &apiKey, &authToken); err != nil {
		log.Fatalln(err)
	} else {
		fmt.Printf("api_key=%s\n", apiKey)
		fmt.Printf("auth_token=%s\n", authToken)
	}
	client := &http.Client{}
	req, err := http.NewRequest("GET", "https://www.box.com/api/2.0/folders/0", nil)
	req.Header.Add("Authorization",
		fmt.Sprintf("BoxAuth api_key=%s&auth_token=%s", apiKey, authToken))
	fmt.Println(req)
	resp, err := client.Do(req)
	fmt.Printf("%v\n", resp)
	defer resp.Body.Close()
	var buf = make([]byte, resp.ContentLength)
	if n, err := resp.Body.Read(buf); n != int(resp.ContentLength) {
		log.Fatalln(err)
	}
    fmt.Println(string(buf))
	var root folder
	if err := json.Unmarshal(buf, &root); err != nil {
		log.Fatalln(err)
	}
	fmt.Println(root)
	id, name = root.Id, root.Name
	fmt.Println(id, name)
	return
}

func main() {
	auth()
}
