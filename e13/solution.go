package e13

import "strings"

func romanToInt(s string) int {
	digits := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}

	romanDigits := strings.Split(s, "")

	var intDigits []int

	for _, d := range romanDigits {
		intDigits = append(intDigits, digits[d])
	}

	number := intDigits[len(intDigits)-1]

	if len(intDigits) > 1 {
		for i := len(intDigits) - 2; i > -1; i-- {
			if intDigits[i+1] > intDigits[i] {
				number = number - intDigits[i]
			} else {
				number = number + intDigits[i]
			}
		}
	}

	return number
}
