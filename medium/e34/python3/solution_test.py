import solution


def test() -> str:
    s = solution.Solution()

    input1 = [[5, 7, 7, 8, 8, 10],
              [5, 7, 7, 8, 8, 10],
              [],
              [1],
              [5, 6, 7, 8, 9],
              [1, 2, 3],
              [1, 4],
              [1, 4],
              [1, 2, 3, 3, 3, 4, 5],
              [3, 3, 3],
              [1, 2, 3, 3, 3, 3, 4, 5, 9],
              [0, 0, 0, 1, 2, 3],
              [0, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 9],
              [0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9]]
    input2 = [8, 6, 0, 1, 7, 0, 1, 4, 3, 3, 3, 0, 7, 1]

    expectations = [[3, 4],   [-1, -1], [-1, -1], [0, 0], [2, 2],
                    [-1, -1], [0, 0],   [1, 1],   [2, 4], [0, 2],
                    [2, 5],   [0, 2],   [15, 17], [1, 3]]

    if (len(input1) != len(input2) or len(input2) != len(expectations) or len(expectations) != len(input1)):
        return "test is invalid"

    for i in range(len(expectations)):
        assert (-10**9 <= input2[i] and input2[i] <= 10**9)

        assert (0 <= len(input1[i]) and len(input1[i]) < 10**5)

        if len(input1[i]) > 0:
            assert (sorted(input1[i]))

        for n in range(len(input1[i])):
            assert (-10**9 < n and n <= 10**9)

        result = s.searchRange(input1[i], input2[i])

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
