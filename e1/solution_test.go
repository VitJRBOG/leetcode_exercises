package e1

import "testing"

func TestTwoSum(t *testing.T) {
	nums := []int{3, 2, 4}
	target := 6

	expected := []int{1, 2}

	result := TwoSum(nums, target)

	if len(result) == len(expected) {
		for i := 0; i < len(expected); i++ {
			if result[i] != expected[i] {
				t.Fatalf("bad result for %v\ngot %v\nexpected %v", nums, result, expected)
			}
		}
	} else {
		t.Fatalf("bad result for %v\ngot %v\nexpected %v", nums, result, expected)
	}
}
