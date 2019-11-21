import unittest
import math
import copy
from collections.abc import *

class TestFunction(unittest.TestCase):
    # def setUp(self):

    def test_type(self):
        a = type(0) is type(99)
        b = type('a') is type(20)
        self.assertEqual(a, True)
        self.assertEqual(b, False)

    def test_callable(self):
        self.assertTrue(callable(list))

    def test_isinstance(self):
        # 是否為某物件的實體
        a  = [0, 1, 2]
        self.assertTrue(isinstance(a, list))

    def test_collections_abc(self):
        a = issubclass(list, Sequence)
        b = issubclass(tuple, Sequence)
        c = issubclass(MutableSequence, Sequence)
        self.assertEqual(a, True)
        self.assertEqual(b, True)
        self.assertEqual(c, True)

    def test_iterable(self):
        # iterable = 可以一個接著一個的東西
        ls = [0, 1, 2]
        lit = iter(ls)
        # 記憶體位置->ls[0]->ls[1]->ls[2]
        self.assertEqual(next(lit), 0)
        self.assertEqual(next(lit), 1)
        self.assertEqual(next(lit), 2)

        # list, tuple, str 都是一種Sequence(序列"抽象"型別)
    
    def test_indexing(self):
        # 索引可以為負
        ls = [30, 41, 52, 63, 74, 85]
        self.assertEqual(ls[-2], 74)

    def test_slicing(self):
        ls = [30, 41, 52, 63, 74, 85]
        self.assertEqual(ls[0:2], [30, 41])
        # 是一個右封閉區間
        self.assertEqual(ls[3:99], [63, 74, 85])
        # 索引值若超過則為序列最大
        self.assertEqual(ls[::-1], [85, 74, 63, 52, 41, 30])
        # 倒轉取值
        u, *v = ls[1::2]
        self.assertEqual(u, 41)
        self.assertEqual(v, [63, 85])

    def test_range(self):
        # range回傳一個iter, 有連續性
        a = list(range(10000))
        # 也是一個右封閉區間只會到9999
        self.assertEqual(a[9999], 9999)

    def test_deepcopy(self):
        ls = [0, 1, 2]
        ls2 = ls
        exp1 = ls is ls2
        ls3 = copy.deepcopy(ls)
        exp2 = ls is ls3
        self.assertEqual(exp1, True)
        self.assertEqual(exp2, False)
# copy.deepcopy() = ls[:] = list(ls) are deepcopy
# operator = , copy.copy() are shallow copy

    def test_enumerable(self):
        b = ['a', 'b', 'c', 'd']
        x = enumerate(b)
        self.assertEqual(next(x), (0, 'a'))
        self.assertEqual(next(x), (1, 'b'))
        self.assertEqual(next(x), (2, 'c'))
        self.assertEqual(next(x), (3, 'd'))

    def test_zip(self):
        a = [0, 1, 2, 3]
        b = ['a', 'b', 'c', 'd']
        ls = list(zip(a, b))
        self.assertEqual(ls, [(0, 'a'), (1, 'b'), (2, 'c'), (3, 'd')])

    def test_zip_with_for(self):
        ls1 = [90, 80, 75, 61, 72]
        ls2 = [-5, -6, -10, 5, 7]
        result = []
        for a, b in zip(ls1, ls2):
            result.append(a+b)
        self.assertEqual(result, [85, 74, 65, 66, 79])


