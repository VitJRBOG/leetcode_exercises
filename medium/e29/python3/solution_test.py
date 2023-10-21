import solution
import unittest


class TestSolution(unittest.TestCase):
    def test(self):
        s = solution.Solution()

        input1 = [10, 7, 1, -1, 2147483647, -
                  2147483648, -2147483648]
        input2 = [3, -3, 1, -1, 3, 3, -1]

        expectations = [3, -2, 1, 1, 715827882, -715827882, 2147483647]

        if (len(input1) != len(expectations)):
            self.fail("Test is invalid")

        for i in range(len(expectations)):
            assert (-2**31 <= input1[i] and input1[i] <= 2**31 - 1)
            assert (-2**31 <= input2[i] and input2[i] <= 2**31 - 1)
            assert (input2[i] != 0)

            result = s.divide(input1[i], input2[i])
            msg = (f"bad result for {input1[i]} and {input2[i]}: got {
                   result} expected {expectations[i]}")

            self.assertEqual(result, expectations[i], msg)


if __name__ == '__main__':
    unittest.main()
