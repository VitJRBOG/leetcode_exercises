package e53

func maxSubArray(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}

	var currentNum int
	var maxNum int

	for i := 0; i < len(nums); i++ {
		if i == 0 {
			currentNum = nums[0]
			maxNum = currentNum
			continue
		}

		if currentNum < 0 {
			currentNum = nums[i]
		} else {
			currentNum += nums[i]
		}

		if currentNum > maxNum {
			maxNum = currentNum
		}
	}

	return maxNum
}
