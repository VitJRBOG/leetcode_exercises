import solution
import unittest


class TestSolution(unittest.TestCase):
    def test_twoSum(self):
        s = solution.Solution()

        input1 = [121, -121, 10]

        expectations = [True, False, False]

        if (len(input1) != len(expectations)):
            self.fail("Test is invalid")

        for i in range(len(expectations)):
            assert (-2**31 <= input1[i] and input1[i] <= 2**31)

            result = s.isPalindrome(input1[i])
            msg = f"bad result for {input1[i]}: got " +\
                f"{result} expected {expectations[i]}"

            self.assertEqual(result, expectations[i], msg)


if __name__ == '__main__':
    unittest.main()
