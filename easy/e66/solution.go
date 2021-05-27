package e66

func plusOne(digits []int) []int {
	carry := 0

	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] < 9 {
			digits[i]++
			carry = 0
			break
		}

		digits[i] = 0
		carry = 1
	}

	if carry > 0 {
		digits = append([]int{1}, digits...)
	}

	return digits
}
