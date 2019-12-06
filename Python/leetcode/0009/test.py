import unittest
from isPalindrome import Solution

class ReverseTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.isPalindrome(121), True)

    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.isPalindrome(-121), False)

    def test_example_3(self):
        s = Solution()
        self.assertEqual(s.isPalindrome(10), False)