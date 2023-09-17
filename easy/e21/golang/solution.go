package golang

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil && list2 == nil {
		return nil
	}

	list0 := &ListNode{}
	nextNode := list0

	for {
		if list1 == nil && list2 == nil {
			break
		} else if list1 != nil && list2 == nil {
			nextNode.Val = list1.Val

			list1 = list1.Next
		} else if list2 != nil && list1 == nil {
			nextNode.Val = list2.Val

			list2 = list2.Next
		} else {
			if list1.Val <= list2.Val {
				nextNode.Val = list1.Val

				list1 = list1.Next
			} else if list2.Val < list1.Val {
				nextNode.Val = list2.Val

				list2 = list2.Next
			}
		}

		if ((list0 == nextNode) && (list1 != nil || list2 != nil)) ||
			((list0 != nextNode) && (list1 != nil || list2 != nil)) {
			nextNode.Next = &ListNode{}
			nextNode = nextNode.Next
		}
	}

	return list0
}
