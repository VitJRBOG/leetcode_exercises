package golang

import (
	"testing"
)

func TestReverse(t *testing.T) {
	input := []int{123, -123, 120, 1534236469, -2147483648, -2147483412}

	expectations := []int{321, -321, 21, 0, 0, -2143847412}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {
		result := reverse(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %d:\ngot %d\nexpectations %d\n", input[i], result, expectations[i])
		}
	}
}
