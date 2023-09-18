package golang

func removeElement(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}

	for i, j := 0, len(nums)-1; i < len(nums) && j >= i; i, j = i+1, j-1 {
		if nums[i] == val {
			nums = append(nums[:i], nums[i+1:]...)
			i--
			j--
		}

		if (len(nums) == 0) || (len(nums) == 1 && nums[0] != val) {
			break
		}

		if nums[j] == val {
			nums = append(nums[:j], nums[j+1:]...)
		}
	}

	return len(nums)
}
