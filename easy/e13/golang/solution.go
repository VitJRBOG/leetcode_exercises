package golang

import "fmt"

func romanToInt(s string) int {
	switch s {
	case "IV":
		return 4
	case "IX":
		return 9
	case "XL":
		return 40
	case "XC":
		return 90
	case "CD":
		return 400
	case "CM":
		return 900
	}

	num := 0

	nums := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	specialNums := map[string]int{
		"IV": 4,
		"IX": 9,
		"XL": 40,
		"XC": 90,
		"CD": 400,
		"CM": 900,
	}

	r := []rune(s)

	for i := 0; i < len(r); i++ {
		if i < len(r)-1 {
			if r[i] == 'I' || r[i] == 'X' || r[i] == 'C' {
				if value, ok := specialNums[fmt.Sprintf("%s%s", string(r[i]), string(r[i+1]))]; ok {
					num += value
					i++
					continue
				}
			}
		}
		num += nums[r[i]]
	}

	return num
}
