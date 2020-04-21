import unittest
import copy

class TestFunction(unittest.TestCase):
    # setUp是每一次打開一個新的Testcase都會re一次
    # 資料會被default一次
    def setUp(self):
        self.dict_1 = {'a': 1, 'b': 2, 'c': 3}
        self.dict_2 = {'d': 4, 'e': 5, 'f': 6}
        self.li_1 = ['a', 'b', 'c']
        self.li_2 = [1, 2, 3]