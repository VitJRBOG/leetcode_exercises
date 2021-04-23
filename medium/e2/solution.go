package e2

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	lHead := ListNode{0, nil}
	l3 := &lHead

	lx := l1
	ly := l2
	carry := 0

	for {
		if lx == nil && ly == nil && carry == 0 {
			break
		}

		lxVal := 0
		lyVal := 0

		if lx != nil {
			lxVal = lx.Val
			lx = lx.Next
		}

		if ly != nil {
			lyVal = ly.Val
			ly = ly.Next
		}

		sum := lxVal + lyVal + carry
		carry = sum / 10

		l3.Next = &ListNode{sum % 10, nil}
		l3 = l3.Next
	}

	return lHead.Next
}
