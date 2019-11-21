import unittest
import math

class TestFunction(unittest.TestCase):
    def setUp(self):
        self.ls_a = [0, 1, 2]
        self.ls_b = [3, 4, 5]

    def test_list_of_list(self):
        ls = ['Frank', 177, 68, 'engineer', ['C', 'Python']]
        self.assertEqual(ls[4][1], 'Python')

    def test_alias(self):
        # 把A指派給B，當改動B時，也會改到A
        a = [60, 71, 82]
        b = a
        b[0] = 99
        self.assertEqual(a[0], 99)

    def test_list_operator(self):
        ls_c = [0, 1, 2] + [3, 4, 5]
        ls_d = [0, 1, 2]*3
        self.assertEqual(ls_c, [0, 1, 2, 3, 4, 5])
        self.assertEqual(ls_d, [0, 1, 2, 0, 1, 2, 0, 1, 2])

    def test_in_operator(self):
        exc1 = 0 in self.ls_a
        exc2 = 3 not in self.ls_a
        self.assertEqual(exc1, True)
        self.assertEqual(exc2, True)
        # 對，3不在ls_a裡面

    def test_is_operator(self):
        ls_c = self.ls_a
        ls_d = [0, 1, 2]
        exc1 = ls_c is self.ls_a
        exc2 = self.ls_b is not self.ls_a
        exc3 = self.ls_a is ls_d
        self.assertEqual(exc1, True)
        self.assertEqual(exc2, True)
        # 對，c不是a
        self.assertEqual(exc3, False)
        # 雖然內容物是一樣的，但配到的是不同記憶體

    def test_starred(self):
        record = ('Jon', 50, 123.45, (12, 18, 2012))
        name, *_, (*_, year) = record
        self.assertEqual(name, 'Jon')
        self.assertEqual(year, 2012)