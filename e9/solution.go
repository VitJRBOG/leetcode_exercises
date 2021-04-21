package e9

func isPalindrome(x int) bool {
	switch true {
	case x < 0:
		return false
	case x == 0:
		return true
	}

	var digits []int

	for x != 0 {
		digits = append(digits, x%10)

		x /= 10
	}

	for i := 0; ; i++ {
		if i <= len(digits)-i {
			if digits[i] != digits[len(digits)-1-i] {
				return false
			}
		} else {
			break
		}
	}

	return true
}
