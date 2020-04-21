import unittest

#這是我看此本書的筆記，其中引入測試以及註解，方便理解。
#請注意，Python的Testcase有其命名格式，隨意命名會使其失效。

class TestFunction(unittest.TestCase):

    def test_list_and_and_tuple(self):
        t0 = (1, 2, 3)
        #這是一個tuple, 無法更改值
        ls_0 = [1, 2, 3]
        #這是一個list, 可以更改值。

    def test_operator_1(self):
        #算數運算子包含+、-、*、/、%、//、**
        n0 = 17/3
        n1 = 17 % 3
        n2 = 17 // 3
        n3 = 2**3
        self.assertEquals(n0, 5.6667, 0.01)
        #浮點數除法-> /
        self.assertEqual(n1, 2)
        self.assertEqual(n2, 5)
        #樓地板除法-> //
        self.assertEqual(n3, 8)
        #指數->**

    def test_operator_2(self):
        #比較運算子有（除了那幾個基本的）<>、==
    #但<>是.2x版本的，又叫!=
        pass

    def test_operator_3(self):
        #成員關係運算子(in)、同等關係運算子(is)
        a = 3
        b = 4
        c = 1+2
        li_0 = [2, 3, 4, 5, 6]
        self.assertEqual(a is not b, True)
        self.assertEqual(a is c, True)
        self.assertEqual(a in li_0, True)
        self.assertEqual(b not in li_0, False)