package e9

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	orig := x
	last := 0
	num := 0

	for {
		if x == 0 {
			break
		}

		last = x % 10
		if num == 0 && last == 0 {
			return false
		}

		num = (num * 10) + last

		x = x / 10
	}

	if num == orig {
		return true
	}

	return false
}
