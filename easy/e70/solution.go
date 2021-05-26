package e70

func climbStairs(n int) int {
	if n == 1 {
		return 1
	}

	f1 := 1
	f2 := 2
	for i := 3; i <= n; i++ {
		f3 := f1 + f2
		f1 = f2
		f2 = f3
	}
	return f2
}
