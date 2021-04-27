package e20

import "testing"

func TestIsValid(t *testing.T) {
	input := []string{"(])", "(}{)", "[", "){", "()", "()[]{}", "(]", "([)]", "{[]}", "({[({})]})"}

	expectations := []bool{false, false, false, false, true, true, false, false, true, true}

	if len(input) == len(expectations) {
		for i := 0; i < len(input); i++ {
			result := isValid(input[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %s\nexpected: %v\ngot: %v\n", input[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and expectations slices\n")
	}
}
