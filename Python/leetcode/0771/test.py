import unittest
from J_and_S import Solution

class UnitTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.numJewelsInStones("aA", "aAAbbbb"), 3)
    
    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.numJewelsInStones("z", "ZZ"), 0)
    
 