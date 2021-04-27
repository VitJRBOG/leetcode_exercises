package e58

import "testing"

func TestLengthOfLastWord(t *testing.T) {
	input := []string{"a ", "Hello World", " "}

	expectations := []int{1, 5, 0}

	if len(input) == len(expectations) {
		for i := 0; i < len(input); i++ {
			result := lengthOfLastWord(input[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %s\nexpected: %d\ngot: %d\n",
					input[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and expectations slices\n")
	}
}
