package golang

func maxSubArray(nums []int) int {
	maxSum := nums[0]
	sum := 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]

		if maxSum < nums[i] {
			maxSum = nums[i]
		}

		if sum < 0 {
			sum = 0
			continue
		}

		if maxSum < sum {
			maxSum = sum
		}
	}

	return maxSum
}
