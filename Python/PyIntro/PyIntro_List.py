import unittest
import copy

class TestFunction(unittest.TestCase):
    # setUp是每一次打開一個新的Testcase都會re一次
    # 資料會被default一次
    def setUp(self):
        pass

    def test_construct_1(self):
        # in-place construction
        arr1 = [i for i in range(10)]
        # you can use if to filter the elements
        arr2 = [x for x in arr1 if x % 2 == 0]
        # you can use as many conditions as you want!
        arr3 = [x for x in arr1 if x >= 3 and x % 2]
        # use nested for loops to make everyone dizzy XD
        arr4 = [(x, y) for x in range(3) for y in range(4)]

        self.assertEqual(arr1, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
        self.assertEqual(arr2, [0, 2, 4, 6, 8])
        self.assertEqual(arr3, [3, 5, 7, 9])
        self.assertEqual(arr4, [(0, 0), (0, 1), (0, 2), (0, 3), (1, 0), (1, 1), (1, 2), (1, 3), (2, 0), (2, 1), (2, 2), (2, 3)])

    # def test_construction_2(self):

