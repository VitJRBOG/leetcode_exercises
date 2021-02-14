package e2

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	num1 := nodeToListInt(l1)
	num2 := nodeToListInt(l2)

	var nums []int
	if len(num1) == len(num2) {
		nums = calcNums(num1, num2)
	} else {
		if len(num1) > len(num2) {
			nums = calcNums(num2, num1)
		} else {
			nums = calcNums(num1, num2)
		}
	}

	result := intListToNode(nums)

	return result
}

func nodeToListInt(n *ListNode) []int {
	var nums []int
	for {
		if n != nil {
			nums = append(nums, n.Val)
			n = n.Next
		} else {
			break
		}
	}

	return nums
}

func calcNums(num1, num2 []int) []int {
	var nums []int

	num1 = reverseIntList(num1)
	num2 = reverseIntList(num2)

	for i := 0; i < len(num2); i++ {
		if i < len(num1) {
			nums = append(nums, num2[i]+num1[i])
		} else {
			nums = append(nums, num2[i])
		}
	}

	for i := 0; i < len(nums); i++ {
		if nums[i] > 9 {
			nums[i] -= 10
			if i == len(nums)-1 {
				nums = append(nums, 1)
			} else {
				nums[i+1] += 1
			}
		}
	}

	nums = reverseIntList(nums)

	return nums
}

func reverseIntList(origList []int) []int {
	var newList []int

	for i := len(origList) - 1; i >= 0; i-- {
		newList = append(newList, origList[i])
	}

	return newList
}

func intListToNode(nums []int) *ListNode {
	var n *ListNode
	for i := 0; i < len(nums); i++ {
		if i == 0 {
			n = &ListNode{nums[i], nil}
		} else {
			rn := ListNode{nums[i], n}
			n = &rn
		}
	}
	return n
}
