package golang

import (
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {
	input := [][]int{{1, 1}, {1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {-71, -13, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 1, 2}, {0, 0, 1, 2, 3, 4, 5, 6, 6, 6}}

	handledInput := [][]int{{1}, {1, 2}, {0, 1, 2, 3, 4}, {-71, -13, 1, 2, 3, 4}, {0, 1, 2}, {0, 1, 2, 3, 4, 5, 6}}
	expectations := []int{1, 2, 5, 6, 3, 7}

	if len(input) != len(handledInput) || len(handledInput) != len(expectations) || len(expectations) != len(input) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {
		result := removeDuplicates(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %d:\nexpected: %d\ngot %d", input[i], expectations[i], result)
		}

		for j := 0; j < len(handledInput[i]); j++ {
			if handledInput[i][j] != input[i][j] {
				t.Fatalf("\nbad result for %d:\nexpected: %d\ngot %d", input[i], expectations[i], result)
			}
		}
	}
}
