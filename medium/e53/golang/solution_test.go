package golang

import "testing"

func TestMaxSubArray(t *testing.T) {
	input := [][]int{{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {5, 4, -1, 7, 8}, {-2, -1}}
	expectations := []int{6, 1, 23, -1}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {

		result := maxSubArray(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %d\nexpected: %d\ngot: %d\n",
				input[i], expectations[i], result)
		}
	}
}
