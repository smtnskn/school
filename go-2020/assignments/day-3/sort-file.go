package main

import (
	"os"
	"sort"
	"path/filepath"
	"bufio"
	"log"
	"strings"
	"fmt"
)

func check_error(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	// Check arguments
	if len(os.Args) != 2 {
		log.Fatalln("ERROR: give a single file path as an argument")
	}

	// Open file
	file_path := os.Args[1]
	file, err := os.Open(file_path)
	check_error(err)

	// Read lines from the file into a slice
	var line string
	line_slice := make([]string, 0)
	reader := bufio.NewReader(file)

	for {
		// Break when there is nothing more to read
		if line, err = reader.ReadString('\n'); err != nil {
			file.Close()
			break
		}
		line_slice = append(line_slice, line)
	}

	// Sort the contents of the slice
	sort.Strings(line_slice)

	// Create a new file
	ext := filepath.Ext(file_path)
	name := strings.TrimSuffix(filepath.Base(file_path), ext)
	new_file_path := fmt.Sprintf("%s/%s-sorted%s", filepath.Dir(file_path), name, ext)
	new_file, err := os.Create(new_file_path)
	check_error(err)

        // Write the sorted contents of the slice into the new file
        writer := bufio.NewWriter(new_file)
        for _, line := range line_slice {
                _, err := writer.WriteString(line) // ignore other retval
                check_error(err)
        }
	check_error(writer.Flush())
	check_error(new_file.Close())
}
