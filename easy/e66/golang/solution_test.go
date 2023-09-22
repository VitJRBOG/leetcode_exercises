package golang

import "testing"

func TestPlusOne(t *testing.T) {
	input := [][]int{{1, 2, 3}, {4, 3, 2, 1}, {0}, {9}}
	expectations := [][]int{{1, 2, 4}, {4, 3, 2, 2}, {1}, {1, 0}}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	if len(input) == len(expectations) {
		for i := 0; i < len(input); i++ {

			result := plusOne(input[i])

			if len(result) != len(expectations[i]) {
				t.Fatalf("\nbad result for %d\nexpected: %d\ngot: %d\n",
					input[i], expectations[i], result)
			} else {
				for n := 0; n < len(result); n++ {
					if result[n] != expectations[i][n] {
						t.Fatalf("\nbad result for %d\nexpected: %d\ngot: %d\n",
							input[i], expectations[i], result)
					}
				}
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and expectations slices\n")
	}
}
