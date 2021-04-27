package e35

import "testing"

func TestSearchInsert(t *testing.T) {
	input1 := [][]int{{1, 3, 5, 6}, {1, 3, 5, 6}, {1, 3, 5, 6}, {1, 3, 5, 6}, {1}}
	input2 := []int{5, 2, 7, 0, 0}

	expectations := []int{2, 1, 4, 0, 0}

	if len(input1) == len(expectations) && len(input2) == len(expectations) {
		for i := 0; i < len(input1); i++ {
			result := searchInsert(input1[i], input2[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
					input1[i], input2[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of inputs and expectations slices\n")
	}
}
