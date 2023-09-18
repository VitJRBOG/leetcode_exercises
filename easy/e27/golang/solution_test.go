package golang

import "testing"

func TestRemoveElement(t *testing.T) {
	input1 := [][]int{{2, 2, 3}, {1}, {3, 2, 2, 3}, {0, 1, 2, 2, 3, 0, 4, 2}, {3, 3}, {5, 2, 5, 5, 5, 3, 7, 4, 5, 8, 9, 5}}
	input2 := []int{2, 1, 3, 2, 3, 5}

	handledInput1 := [][]int{{3}, {}, {2, 2}, {0, 1, 3, 0, 4}, {}, {2, 3, 7, 4, 8, 9}}

	expectations := []int{1, 0, 2, 5, 0, 6}

	if len(input1) != len(input2) || len(input2) != len(handledInput1) || len(handledInput1) != len(expectations) || len(expectations) != len(input1) {
		t.Fatal("test is invalid")
	}

	if len(input1) == len(input2) && len(input1) == len(expectations) && len(input2) == len(expectations) {
		for i := 0; i < len(input1); i++ {
			origInput1 := make([]int, len(input1[i]))

			copy(origInput1, input1[i])

			result := removeElement(input1[i], input2[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
					origInput1, input2[i], expectations[i], result)
			}

			for j := 0; j < len(handledInput1[i]); j++ {
				if input1[i][j] != handledInput1[i][j] {
					t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
						origInput1, input2[i], expectations[i], result)
				}
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and output slices\n")
	}
}
