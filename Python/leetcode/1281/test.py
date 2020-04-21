import unittest
from subtractProductAndSum import Solution

class ReverseTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.subtractProductAndSum(234), 15)
    
    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.subtractProductAndSum(4421), 21) 
    
 