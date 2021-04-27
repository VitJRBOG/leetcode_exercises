package e58

func lengthOfLastWord(s string) int {
	var wordLength int
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != ' ' {
			wordLength++
		} else {
			if wordLength > 0 {
				break
			}
		}
	}
	return wordLength
}
