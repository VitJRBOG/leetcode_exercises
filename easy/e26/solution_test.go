package e26

import "testing"

func TestRemoveDuplicates(t *testing.T) {
	input := [][]int{{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {1, 1, 2}, {1, 2, 3, 4, 5, 6, 6, 6}}

	expectations := []int{5, 2, 6}

	for i := 0; i < len(input); i++ {
		result := removeDuplicates(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %d:\nexpected: %d\ngot %d", input[i], expectations[i], result)
		}
	}
}
