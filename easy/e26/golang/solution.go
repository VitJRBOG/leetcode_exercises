package golang

func removeDuplicates(nums []int) int {
	if len(nums) == 1 {
		return 1
	}

	for i, j := 0, len(nums)-1; i+1 < len(nums) && j >= i && j > 0; i, j = i+1, j-1 {
		if nums[i] == nums[i+1] {
			nums = append(nums[:i], nums[i+1:]...)
			i--
			j--
		}

		if j == 0 {
			break
		}

		if nums[j] == nums[j-1] {
			nums = append(nums[:j-1], nums[j:]...)
		}
	}

	return len(nums)
}
