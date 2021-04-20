package e7

import "math"

func Reverse(x int) int {
	var reversedNumber int

	for {
		if x == 0 {
			break
		} else {
			y := x % 10

			switch true {
			case reversedNumber > math.MaxInt32/10:
				return 0
			case reversedNumber < math.MinInt32/10:
				return 0
			}

			reversedNumber *= 10
			reversedNumber += y
			x /= 10
		}
	}
	return reversedNumber
}
