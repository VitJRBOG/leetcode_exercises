package golang

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}

	indexOfShortestWord := 0

	for i := 1; i < len(strs); i++ {
		if indexOfShortestWord != i && len(strs[indexOfShortestWord]) > len(strs[i]) {
			indexOfShortestWord = i
		}
	}

	prefix := []byte(strs[indexOfShortestWord])

	for i := 0; i < len(strs); i++ {
		if len(prefix) == 0 {
			break
		}

		if i != indexOfShortestWord {
			for j := 0; j < len(prefix); j++ {
				if strs[i][j] != prefix[j] {
					prefix = prefix[:j]
					break
				}
			}
		}
	}

	return string(prefix)
}
