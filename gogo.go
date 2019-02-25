package main

import "fmt"

func main() {
	fmt.Println("hello world")
	var v1 int = 1
	fmt.Println(v1)
	var v2 [5]int
	fmt.Println(v2)
	v2[1] = 1
	fmt.Println(v2)
	// b := [5]int{1, 2, 3, 4, 5}
	if v1%2 == 0 {
		fmt.Println("fuck me")
	} else {
		fmt.Println("fuck you")
	}
	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}
	m1 := make(map[int]string)
	m1[1] = "one"
	fmt.Println(m1)
	m2 := map[string]int{"one": 1, "two": 2}
	fmt.Println(m2)
	for key := range m2 {
		fmt.Println(key)
	}
	fmt.Println(better(1, 2))
	fmt.Println(both(1, 2))
	re := rect{width: 10, height: 15}
	fmt.Println(re.area())
}

func better(a int, b int) int { //注意参数和返回值是怎么声明的

	if a > b {
		return a
	}
	return b
}

func both(a int, b int) (int, int) {
	return a, b
}

type rect struct {
	width, height int
}

func (r *rect) area() int { //求面积
	return r.width * r.height
}

func (r *rect) perimeter() int { //求周长
	return 2 * (r.width + r.height)
}
