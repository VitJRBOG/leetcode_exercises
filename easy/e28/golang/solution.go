package golang

func strStr(haystack string, needle string) int {
	if len(needle) > len(haystack) {
		return -1
	}

OUTER:
	for i := 0; i < len(haystack); i++ {
		if len(needle)-1 <= len(haystack)-1-i {
			if needle[0] == haystack[i] && needle[len(needle)-1] == haystack[i+len(needle)-1] {
				for j := 1; j < len(needle)-1; j++ {
					if needle[j] != haystack[i+j] {
						continue OUTER
					}
				}
				return i
			}
		} else {
			break
		}
	}

	return -1
}
