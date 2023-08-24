package golang

import "testing"

func TestTwoSum(t *testing.T) {
	nums := [][]int{{3, 2, 4}, {2, 7, 11, 15}}
	target := []int{6, 9}

	expected := [][]int{{1, 2}, {0, 1}}

	if len(nums) != len(target) || len(target) != len(expected) || len(expected) != len(nums) {
		t.Fatal("test is invalid")
	}

	for i := range nums {
		result := twoSum(nums[i], target[i])

		if len(result) == len(expected[i]) {
			for j := range expected[i] {
				if result[j] != expected[i][j] {
					t.Fatalf("bad result for %v and %v\ngot %v\nexpected %v", nums[i], target[i], result, expected[i])
				}
			}
		} else {
			t.Fatalf("bad result for %v and %v\ngot %v\nexpected %v", nums[i], target[i], result, expected[i])
		}
	}
}
