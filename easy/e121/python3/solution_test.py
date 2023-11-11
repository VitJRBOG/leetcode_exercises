import solution


def test() -> str:
    s = solution.Solution()

    input1 = [[6, 1, 3, 2, 4, 7], [1, 4, 2], [3, 3, 5, 0, 0, 3, 1, 4], [7, 1, 5, 3, 6, 4], [
        7, 6, 4, 3, 1], [2, 7, 1, 4], [3, 2, 6, 5, 0, 3]]

    expectations = [6, 3, 4, 5, 0, 5, 4]

    if (len(input1) != len(expectations)):
        return "test is invalid"

    for i in range(len(expectations)):
        assert (1 <= len(input1[i]) and len(input1[i]) < 10**5)

        for j in range(len(input1[i])):
            assert (0 <= input1[i][j] and input1[i][j] <= 10**4)

        origInput1 = input1[i][:]

        result = s.maxProfit(input1[i])

        failMsg = (f"bad result for {origInput1}: got {
                   result} expected {expectations[i]}")

        if result != expectations[i]:
            return failMsg

    return "PASS"


if __name__ == '__main__':
    print(test())
