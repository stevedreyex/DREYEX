import unittest
from removeElement import Solution

class UnitTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.removeElement([3,2,2,3], 3), [2,2])

    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.removeElement([0,1,2,2,3,0,4,2], 2), [0,1,3,0,4])