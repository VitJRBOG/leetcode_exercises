package e14

func longestCommonPrefix(strs []string) string {
	var prefix []rune

	i, n := 0, 0
	for {
		if i >= len(strs) {
			i = 0
			n++
		}

		runes := []rune(strs[i])

		if len(runes) == 0 {
			return ""
		}

		if n >= len(runes) {
			if i > 0 {
				prefix = prefix[:n]
			}
			break
		}

		if i == 0 {
			prefix = append(prefix, runes[n])
			i++
			continue
		}

		if prefix[n] == runes[n] {
			i++
			continue
		}

		if n == 0 && prefix[n] != runes[n] {
			return ""
		}

		if n > 0 && prefix[n] != runes[n] {
			prefix = prefix[:n]
		}

		break
	}

	return string(prefix)
}
