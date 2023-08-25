package e9

import "testing"

func TestIsPalindrome(t *testing.T) {
	input := []int{123, 111, 101, 10, 11, -101, 12300321, 1, 0}

	expectations := []bool{false, true, true, false, true, false, true, true, true}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {
		result := isPalindrome(input[i])
		if result != expectations[i] {
			t.Fatalf("\nbad result for %d\nexpected %v\ngot %v", input[i], expectations[i], result)
		}
	}
}
