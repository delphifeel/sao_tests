package main

import "fmt"

const COUNT = 99999999

type Tag struct {
	v1 uint
	v2 uint
	v3 uint
	v4 uint64
}

func Init(i uint) Tag {
	return Tag{
		v1: i * 2,
		v2: i * 3,
		v3: i * 4,
	}
}

func Tag_Same(tag1 *Tag, tag2 *Tag) bool {
	if tag1.v1 != tag2.v1 {
		return false
	}
	if tag1.v2 != tag2.v2 {
		return false
	}
	if tag1.v3 != tag2.v3 {
		return false
	}
	return true
}

func main() {
	v := make([]Tag, 0, COUNT)

	// push
	for i := uint(0); i < COUNT; i++ {
		v = append(v, Init(i))
	}

	// find
	tag_to_find := Init(COUNT / 2)
	for i := range v {
		if Tag_Same(&tag_to_find, &v[i]) {
			fmt.Printf("We found it\n")
		}
	}
}
