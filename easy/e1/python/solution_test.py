import solution
import unittest


class TestSolution(unittest.TestCase):
    def test_twoSum(self):
        s = solution.Solution()

        input1 = [[2, 7, 11, 15], [3, 2, 4], [3, 3]]
        input2 = [9, 6, 6]

        expectations = [[0, 1], [1, 2], [0, 1]]

        if (
            len(input1) != len(input2)
            or len(input2) != len(expectations)
            or len(expectations) != len(input1)
        ):
            self.fail("Test is invalid")

        for i in range(len(expectations)):
            origInput1 = input1[i].copy()

            assert (2 <= len(input1[i]) and len(input1[i]) <= 10**4)
            assert (-10**9 <= input2[i] and input2[i] <= 10**9)

            for j in range(len(input1[i])):
                assert (-10**9 <= input1[i][j] and input1[i][j] <= 10**9)

            result = s.twoSum(input1[i], input2[i])
            msg = f"bad result for {origInput1} and " +\
                f"{input2[i]} got {result} expected {expectations[i]}"

            self.assertEqual(result, expectations[i], msg)


if __name__ == '__main__':
    unittest.main()
