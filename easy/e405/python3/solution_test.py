import solution
import unittest


class TestSolution(unittest.TestCase):
    def test(self):
        s = solution.Solution()

        input1 = [26, 1000, 1982653, 2147483647, 0, -1, -2147483648, -2]

        expectations = ["1a", "3e8", "1e40bd",
                        "7fffffff", "0", "ffffffff", "80000000", "fffffffe"]

        if (len(input1) != len(expectations)):
            self.fail("Test is invalid")

        for i in range(len(expectations)):
            assert (-2**31 <= input1[i] and input1[i] <= 2**31-1)

            result = s.toHex(input1[i])
            msg = (f"bad result for {input1[i]}: got {
                   result} expected {expectations[i]}")

            self.assertEqual(result, expectations[i], msg)


if __name__ == '__main__':
    unittest.main()
