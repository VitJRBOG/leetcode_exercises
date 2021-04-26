package e28

import "testing"

func TestStrStr(t *testing.T) {
	input1 := []string{"hello", "aaaaa", ""}
	input2 := []string{"ll", "bba", ""}

	expectations := []int{2, -1, 0}

	if len(input1) == len(input2) && len(input1) == len(expectations) && len(input2) == len(expectations) {
		for i := 0; i < len(input1); i++ {
			result := strStr(input1[i], input2[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %s and %s\nexpected: %d\ngot: %d\n",
					input1[i], input2[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and expectations slices\n")
	}
}
