package golang

func merge(nums1 []int, m int, nums2 []int, n int) {
	i := m
	j := n - 1
	for {
		if j < 0 {
			break
		}

		if i > 0 && nums1[i-1] > nums2[j] {
			i--
			continue
		}

		nums1 = append(nums1[:i+1], nums1[i:len(nums1)-1]...)
		nums1[i] = nums2[j]

		j--
	}
}
