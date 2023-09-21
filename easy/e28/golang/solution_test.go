package golang

import "testing"

func TestStrStr(t *testing.T) {
	input1 := []string{"a", "aaa", "sadbutsad", "leetcode", "hello", "aaaaa", "mississippi"}
	input2 := []string{"a", "aaaa", "sad", "leeto", "ll", "bba", "issip"}

	expectations := []int{0, -1, 0, -1, 2, -1, 4}

	if len(input1) != len(input2) || len(input2) != len(expectations) || len(expectations) != len(input1) {
		t.Fatal("test is invalid")
	}

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
