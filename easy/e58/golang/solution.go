package golang

func lengthOfLastWord(s string) int {
	if len(s) == 1 {
		return 1
	}

	length := 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != 32 {
			length++
		} else if length > 0 {
			break
		}
	}

	return length
}
