import unittest
from reverse import Solution

class ReverseTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.reverse(123), 321)

    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.reverse(-123), -321)

    def test_example_3(self):
        s = Solution()
        self.assertEqual(s.reverse(120), 21)

    def test_example_4(self):
        s = Solution()
        self.assertEqual(s.reverse(1534236469), 0)

    def test_example_5(self):
        s = Solution()
        self.assertEqual(s.reverse(-2147483648), 0)

        