package golang

import "testing"

func TestLengthOfLastWord(t *testing.T) {
	input := []string{"b", "a ", "Hello World", "   fly me   to   the moon  ", "luffy is still joyboy"}

	expectations := []int{1, 1, 5, 4, 6}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

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
