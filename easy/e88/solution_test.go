package e88

import "testing"

func TestMerge(t *testing.T) {
	inputs1 := [][]int{{1, 2, 3, 0, 0, 0}}
	inputs2 := []int{3}
	inputs3 := [][]int{{2, 5, 6}}
	inputs4 := []int{3}

	expectations := [][]int{{1, 2, 2, 3, 5, 6}}

	if len(inputs1) == len(inputs3) && len(inputs2) == len(inputs4) &&
		len(inputs1) == len(expectations) && len(inputs2) == len(expectations) {
		for i := 0; i < len(inputs1); i++ {
			result := inputs1[i]
			merge(result, inputs2[i], inputs3[i], inputs4[i])
			if len(result) != len(expectations[i]) {
				t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
					inputs1[i], inputs3[i], expectations[i], result)
			}
			for n := 0; n < len(expectations[i]); n++ {
				if result[n] != expectations[i][n] {
					t.Fatalf("\nbad result for %d and %d\nexpected: %d\ngot: %d\n",
						inputs1[i], inputs2[i], expectations[i], result)
				}
			}
		}
	} else {
		t.Fatalf("\nwrong test: different length of inputs and expectations slices\n")
	}
}
