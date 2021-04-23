package e21

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	lHead := ListNode{0, nil}
	l3 := &lHead

	lx := l1
	ly := l2

	for {
		if lx == nil && ly == nil {
			break
		}

		switch true {
		case lx != nil && ly != nil:
			switch true {
			case lx.Val == ly.Val:
				l3.Next = &ListNode{lx.Val, &ListNode{ly.Val, nil}}
				l3 = l3.Next.Next
				lx = lx.Next
				ly = ly.Next
			case ly.Val > lx.Val:
				l3.Next = &ListNode{lx.Val, nil}
				l3 = l3.Next
				lx = lx.Next
			case lx.Val > ly.Val:
				l3.Next = &ListNode{ly.Val, nil}
				l3 = l3.Next
				ly = ly.Next
			}
		case ly == nil && lx != nil:
			l3.Next = &ListNode{lx.Val, nil}
			l3 = l3.Next
			lx = lx.Next
		case lx == nil && ly != nil:
			l3.Next = &ListNode{ly.Val, nil}
			l3 = l3.Next
			ly = ly.Next
		}
	}

	return lHead.Next
}
