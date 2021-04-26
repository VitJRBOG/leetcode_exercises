package e27

import "testing"

func TestRemoveElement(t *testing.T) {
	input1 := [][]int{{3, 3}, {3, 2, 2, 3}, {0, 1, 2, 2, 3, 0, 4, 2}, {5, 2, 5, 5, 5, 3, 7, 4, 5, 8, 9, 5}}
	input2 := []int{3, 3, 2, 5}

	expectations := []int{0, 2, 5, 6}

	if len(input1) == len(input2) && len(input1) == len(expectations) && len(input2) == len(expectations) {
		for i := 0; i < len(input1); i++ {
			result := removeElement(input1[i], input2[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
					input1[i], input2[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and output slices\n")
	}
}
