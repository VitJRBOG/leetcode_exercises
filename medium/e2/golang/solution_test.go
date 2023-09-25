package golang

import (
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	input1 := [][]int{{2, 4, 3}, {0}, {9, 9, 9, 9, 9, 9, 9}, {5, 6}, {3, 2, 5, 9, 0, 5, 0, 1, 5, 1}}
	input2 := [][]int{{5, 6, 4}, {0}, {9, 9, 9, 9}, {5, 4, 9}, {7, 7, 8, 5, 5, 3, 4, 9, 8}}

	expectations := [][]int{{7, 0, 8}, {0}, {8, 9, 9, 9, 0, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 4, 5, 6, 8, 4, 0, 4, 2}}

	if len(input1) != len(input2) || len(input2) != len(expectations) || len(expectations) != len(input1) {
		t.Fatal("test if invalid")
	}

	for i := 0; i < len(input1); i++ {

		l1Head := ListNode{0, nil}
		l1 := &l1Head

		for n := 0; n < len(input1[i]); n++ {
			l1.Next = &ListNode{input1[i][n], nil}
			l1 = l1.Next
		}

		l2Head := ListNode{0, nil}
		l2 := &l2Head

		for n := 0; n < len(input2[i]); n++ {
			l2.Next = &ListNode{input2[i][n], nil}
			l2 = l2.Next
		}

		l3 := addTwoNumbers(l1Head.Next, l2Head.Next)
		var lz *ListNode
		lz = l3

		var result []int
		for {
			result = append(result, lz.Val)
			if lz.Next != nil {
				lz = lz.Next
			} else {
				break
			}
		}

		if len(result) != len(expectations[i]) {
			t.Fatalf("\nbad result for %d and %d\nexpected %d\ngot %d\n", input1[i], input2[i], expectations[i], result)
		} else {
			for n := 0; n < len(result); n++ {
				if result[n] != expectations[i][n] {
					t.Fatalf("\nbad result for %d and %d\nexpected %d\ngot %d\n", input1[i], input2[i], expectations[i], result)
					break
				}
			}
		}
	}
}
