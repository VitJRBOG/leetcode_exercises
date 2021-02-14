package e2

import (
	"strconv"
	"strings"
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {

	num1 := []int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
	num2 := []int{5, 6, 4}

	var l1 *ListNode
	for i := 0; i < len(num1); i++ {
		if i == 0 {
			l1 = &ListNode{num1[i], nil}
		} else {
			rn := ListNode{num1[i], l1}
			l1 = &rn
		}
	}

	var l2 *ListNode
	for i := 0; i < len(num2); i++ {
		if i == 0 {
			l2 = &ListNode{num2[i], nil}
		} else {
			rn := ListNode{num2[i], l2}
			l2 = &rn
		}
	}

	expected := []int{6, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}

	result := AddTwoNumbers(l1, l2)

	var strResult string
	for {
		if result != nil {
			strResult += strconv.Itoa(result.Val)
			result = result.Next
		} else {
			break
		}
	}
	s := strings.Split(strResult, "")

	var r []int

	for _, item := range s {
		n, err := strconv.Atoi(item)
		if err != nil {
			panic(err.Error())
		}
		r = append(r, n)
	}

	if len(r) == len(expected) {
		for i := 0; i < len(r); i++ {
			if r[i] != expected[i] {
				t.Fatalf("bad result for %v and %v\ngot %v\nexpected %v", num1, num2, r, expected)
			}
		}
	} else {
		t.Fatalf("bad result for %v and %v\ngot %v\nexpected %v", num1, num2, r, expected)
	}

}
