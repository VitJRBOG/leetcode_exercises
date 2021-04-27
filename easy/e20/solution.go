package e20

func isValid(s string) bool {
	if len(s) == 1 {
		return false
	}

	parentheses := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	if _, ok := parentheses[rune(s[len(s)-1])]; !ok {
		return false
	}

	var openParentheses []rune
	var stack int

	for i, item := range s {
		if _, ok := parentheses[item]; ok {
			if i == 0 {
				return false
			}

			if stack > 0 {
				if openParentheses[stack-1] == parentheses[item] {
					stack--
					openParentheses = openParentheses[:stack]
				} else {
					return false
				}
			} else {
				return false
			}
		} else {
			openParentheses = append(openParentheses, item)
			stack++
		}
	}

	return len(openParentheses) == 0
}
