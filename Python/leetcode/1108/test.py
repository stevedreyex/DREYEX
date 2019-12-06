import unittest
from IP_defanging import Solution

class ReverseTest(unittest.TestCase):
    def test_example_1(self):
        s = Solution()
        self.assertEqual(s.defanging("1.1.1.1"), "1[.]1[.]1[.]1")
    
    def test_example_2(self):
        s = Solution()
        self.assertEqual(s.defanging("255.100.50.0"), "255[.]100[.]50[.]0")
    
 