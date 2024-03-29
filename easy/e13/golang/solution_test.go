package golang

import "testing"

func TestRomanToInt(t *testing.T) {
	input := []string{"III", "IV", "IX", "LVIII", "MCMXCIV"}

	expectations := []int{3, 4, 9, 58, 1994}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {
		result := romanToInt(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %s:\nexpected %d\ngot %d", input[i], expectations[i], result)
		}
	}
}
