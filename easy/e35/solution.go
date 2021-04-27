package e35

func searchInsert(nums []int, target int) int {
	for i := 0; ; i++ {
		if i >= len(nums) {
			return i
		}
		if nums[i] == target || nums[i] > target {
			return i
		}
	}
}
