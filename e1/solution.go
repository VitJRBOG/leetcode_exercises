package e1

func TwoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for n := 0; n < len(nums) && n != i; n++ {
			if nums[i]+nums[n] == target {
				var result = []int{n, i}
				return result
			}
		}
	}

	return []int{}
}
