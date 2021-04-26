package e27

func removeElement(nums []int, val int) int {
LOOP:
	for i := 0; i < len(nums); i++ {
		found := false

		if nums[i] == val {
			if i < len(nums)-1 {
				nums = append(nums[:i], nums[i+1:]...)
			} else {
				nums = nums[:i]
			}
			found = true
		}

		if found {
			goto LOOP // потому что это быстрее, чем еще один цикл над этим
		}
	}

	return len(nums)
}
