package e14

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}

	prefix, char := "", ""
	i, n := 0, 0

	for {
		if i >= len(strs) {
			i = 0
			prefix += char
			n++
		}

		if n >= len(strs[i]) {
			break
		}

		if i == 0 {
			char = string(strs[i][n])
			i++
			continue
		}

		if char != string(strs[i][n]) {
			break
		}

		i++
	}

	return prefix
}
