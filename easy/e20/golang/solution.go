package golang

// (, ) = 40, 41
// [, ] = 91, 93
// {, } = 123, 125

func isValid(s string) bool {
	if len(s) == 1 {
		return false
	}

	if len(s)%2 != 0 {
		return false
	}

	breaketsQueue := make([]byte, 0, len(s)/2)
	for i := 0; i < len(s); i++ {
		if s[i] == 40 || s[i] == 91 || s[i] == 123 {
			if i == len(s)-1 {
				return false
			}

			switch s[i] {
			case 40:
				breaketsQueue = append(breaketsQueue, 40)
			case 91:
				breaketsQueue = append(breaketsQueue, 91)
			case 123:
				breaketsQueue = append(breaketsQueue, 123)
			}
		} else if len(breaketsQueue) == 0 {
			return false
		} else {
			switch s[i] {
			case 41:
				if breaketsQueue[len(breaketsQueue)-1] != 40 {
					return false
				}
			case 93:
				if breaketsQueue[len(breaketsQueue)-1] != 91 {
					return false
				}
			case 125:
				if breaketsQueue[len(breaketsQueue)-1] != 123 {
					return false
				}
			}

			breaketsQueue = breaketsQueue[:len(breaketsQueue)-1]

			continue
		}
	}

	if len(breaketsQueue) > 0 {
		return false
	}

	return true
}
