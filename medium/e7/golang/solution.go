package golang

func reverse(x int) int {
	n := 0
	i := 10

	for {
		n = (n * i) + (x % i)
		x /= i

		if x == 0 {
			break
		}

		if x < 0 && n > 0 {
			n *= -1
		}
	}

	if n > 2147483647 || n < -2147483648 {
		return 0
	}

	return n
}
