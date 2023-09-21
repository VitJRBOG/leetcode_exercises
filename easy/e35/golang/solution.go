package golang

func searchInsert(nums []int, target int) int {
	if len(nums) == 1 {
		if target <= nums[0] {
			return 0
		}
		return 1
	}

	if nums[len(nums)/2] == target {
		return len(nums) / 2
	} else if nums[len(nums)/2] > target {
		return searchInsert(nums[:len(nums)/2], target)
	} else {
		return searchInsert(nums[len(nums)/2:], target) + len(nums)/2
	}
}
