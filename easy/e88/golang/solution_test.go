package golang

import "testing"

func TestMerge(t *testing.T) {
	input1 := [][]int{{1, 2, 3, 0, 0, 0}, {4, 5, 6, 0, 0, 0}, {2, 0}, {1}, {0}, {0, 0, 0, 0, 0}}
	input2 := [][]int{{2, 5, 6}, {1, 2, 3}, {1}, {}, {1}, {1, 2, 3, 4, 5}}

	len1 := []int{3, 3, 1, 1, 0, 0}
	len2 := []int{3, 3, 1, 0, 1, 5}

	expectations := [][]int{{1, 2, 2, 3, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2}, {1}, {1}, {1, 2, 3, 4, 5}}

	if len(input1) != len(input2) || len(input2) != len(expectations) || len(expectations) != len(input1) ||
		len(len1) != len(len2) || len(len2) != len(input1) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input1); i++ {
		in1 := make([]int, len(input1[i]))
		copy(in1, input1[i])

		merge(input1[i], len1[i], input2[i], len2[i])

		if len(input1[i]) == len(expectations[i]) {
			for j := 0; j < len(expectations[i]); j++ {
				if input1[i][j] != expectations[i][j] {
					t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
						in1, input2[i], expectations[i], input1[i])
				}
			}
		} else {
			t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
				in1, input2[i], expectations[i], input1[i])
		}
	}
}
