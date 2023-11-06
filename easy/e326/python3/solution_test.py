import solution


def test() -> str:
    s = solution.Solution()

    input1 = [27, 0, -1, 9, 1]

    expectations = [True, False, False, True, True]

    if len(input1) != len(expectations):
        return "test is invalid"

    for i in range(len(expectations)):
        assert (-2**31 <= input1[i] and input1[i] <= 2**31-1)

        result = s.isPowerOfThree(input1[i])

        failMsg = (f"TEST #{i} FAILED: bad result for {input1[i]}: got {
                   result} expected {expectations[i]}")

        if result != expectations[i]:
            return failMsg

    return "PASS"


if __name__ == '__main__':
    print(test())
