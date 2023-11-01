import solution


def test() -> str:
    s = solution.Solution()

    input1 = [[5, 3, 2, 1, 6, 8, 2, 3, 5, 8, 9], [
        1, 2, 5, 2, 3], [1, 2, 5, 2, 3], [1, 2, 5, 2, 3]]
    input2 = [5, 2, 3, 5]

    expectations = [[5, 6], [1, 2], [3], [4]]

    if (len(input1) != len(input2) or len(input2) != len(expectations) or len(expectations) != len(input1)):
        return "test is invalid"

    for i in range(len(expectations)):
        assert (1 <= input2[i] and input2[i] <= 100)

        assert (1 <= len(input1[i]) and len(input1[i]) <= 100)

        for n in input1[i]:
            assert (1 <= n and n <= 100)

        result = s.targetIndices(input1[i], input2[i])

        failMsg = (f"bad result for {input1[i]} and {input2[i]}: got {
                   result} expected {expectations[i]}")

        if len(result) != len(expectations[i]):
            return failMsg

        for j in range(len(result)):
            if result[j] != expectations[i][j]:
                return failMsg

    return "PASS"


if __name__ == '__main__':
    print(test())
