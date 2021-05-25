package e88

import "sort"

func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		return
	}

	for i := 0; i < len(nums1); i++ {
		if nums1[i] == 0 {
			nums1[i] = nums2[0]
			n--
			if n == 0 {
				break
			}
			nums2 = nums2[1:]
		}
	}

	sort.Ints(nums1)
}
