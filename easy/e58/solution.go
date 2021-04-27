package e58

import "strings"

func lengthOfLastWord(s string) int {
	words := strings.Split(s, " ")

	for i := len(words) - 1; i >= 0; i-- {
		if words[i] != "" {
			return len([]rune(words[i]))
		}
	}

	return 0
}
