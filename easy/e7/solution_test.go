package e7

import (
	"testing"
)

func TestReverse(t *testing.T) {
	input := []int{120, 1534236469, -2147483648, -2147483412}

	expected := []int{21, 0, 0, -2143847412}

	for i := 0; i < len(input); i++ {
		result := Reverse(input[i])

		if result != expected[i] {
			t.Fatalf("\nbad result for %d:\ngot %d\nexpectations %d\n", input[i], result, expected[i])
		}
	}
}
