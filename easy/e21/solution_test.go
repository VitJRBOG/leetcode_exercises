package e21

import "testing"

func TestMergeTwoLists(t *testing.T) {
	input1 := [][]int{{1, 2, 4}, {}, {}, {0, 1, 4, 6, 7, 8, 9}}
	input2 := [][]int{{1, 3, 4}, {}, {0}, {0, 1, 1, 1, 3, 5, 6, 7, 7, 8, 9, 9}}

	expectations := [][]int{{1, 1, 2, 3, 4, 4}, {}, {0}, {0, 0, 1, 1, 1, 1, 3, 4, 5, 6, 6, 7, 7, 7, 8, 8, 9, 9, 9}}

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

		l3 := mergeTwoLists(l1Head.Next, l2Head.Next)

		var result []int
		if l3 != nil {
			var lz *ListNode
			lz = l3
			for {
				result = append(result, lz.Val)
				if lz.Next != nil {
					lz = lz.Next
				} else {
					break
				}
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
