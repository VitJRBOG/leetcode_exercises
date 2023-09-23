package golang

func climbStairs(n int) int {
	fn := 1
	fm := 1

	for i := 1; i <= n; i++ {
		fn, fm = fm, fn+fm
	}

	return fn
}
