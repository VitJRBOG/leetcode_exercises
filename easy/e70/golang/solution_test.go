package golang

import "testing"

func TestClimbStairs(t *testing.T) {
	input := []int{2, 3, 4, 5, 45}
	expectations := []int{2, 3, 5, 8, 1836311903}

	if len(input) != len(expectations) {
		t.Fatal("test is invalid")
	}

	for i := 0; i < len(input); i++ {
		result := climbStairs(input[i])

		if result != expectations[i] {
			t.Fatalf("\nbad result for %d\nexpected: %d\ngot: %d\n",
				input[i], expectations[i], result)
		}
	}
}
