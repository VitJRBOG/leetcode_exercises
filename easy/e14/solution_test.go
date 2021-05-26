package e14

import "testing"

func TestLongestCommonPrefix(t *testing.T) {
	input := [][]string{{"flower", "flow", "flight"}, {"dog", "racecar", "car"},
		{""}, {"war"}, {"ab", "a"}}
	expectations := []string{"fl", "", "", "war", "a"}

	if len(input) == len(expectations) {
		for i := 0; i < len(input); i++ {

			result := longestCommonPrefix(input[i])

			if result != expectations[i] {
				t.Fatalf("\nbad result for %s\nexpected: %s\ngot: %s\n",
					input[i], expectations[i], result)
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of input and expectations slices\n")
	}
}
