package golang

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l0Head := &ListNode{}
	l0 := l0Head

	ten := 0

	for {
		if l1 != nil && l2 == nil {
			l0.Val = l1.Val

			l1 = l1.Next

			if ten > 0 {
				l0.Val += ten
				ten--
			}

			if l0.Val > 9 {
				l0.Val %= 10
				ten++
			}
		} else if l2 != nil && l1 == nil {
			l0.Val = l2.Val

			l2 = l2.Next

			if ten > 0 {
				l0.Val += ten
				ten--
			}

			if l0.Val > 9 {
				l0.Val %= 10
				ten++
			}
		} else if l1 != nil && l2 != nil {
			l0.Val = l1.Val + l2.Val

			l1 = l1.Next
			l2 = l2.Next

			if ten > 0 {
				l0.Val += ten
				ten--
			}

			if l0.Val > 9 {
				l0.Val %= 10
				ten++
			}
		} else {
			if ten > 0 {
				l0.Next = &ListNode{}
				l0 = l0.Next
				l0.Val += ten
				ten--
			}
			break
		}

		if l1 != nil || l2 != nil {
			l0.Next = &ListNode{}
			l0 = l0.Next
		}
	}

	return l0Head
}
