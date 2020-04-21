import unittest
import copy

class TestFunction(unittest.TestCase):
    # setUp是每一次打開一個新的Testcase都會re一次
    # 資料會被default一次
    def setUp(self):
        self.li_a = [1, 2, 3]
        self.li_b = [4, 5, 6]
    # 此章節Sequence提到的是有關序列的型別，
    # 而此類型別有共同介面得以操作
    # 只要是list, tulple, string皆可操作
    # 但string 會再用另一章節解釋
    def test_in(self):
        self.assertTrue(1 in self.li_a)
        self.assertFalse(1 not in self.li_a)

    def test_is(self):
        self.assertTrue([1, 2, 3] is not self.li_a)
        # 因為是不同的記憶體，所以不是同物件
        li_x = self.li_a
        self.assertTrue(li_x is self.li_a)
        # =運算子是shallow copy, 所以是同物件
        li_y = copy.deepcopy(self.li_a)
        self.assertTrue(li_y is not self.li_a)
        #  = copy.deepcopy(li)是深拷貝，所以是不同物件（要import copy）

    # def test_cmp(self):
    #     self.assertEqual(-1, cmp(self.li_a, self.li_b))
    #     self.assertEqual(1, cmp(self.li_b, self.li_a))
    # 2.x才有

    def test_plus(self):
        self.assertEqual([1, 2, 3, 4, 5, 6], self.li_a + self.li_b)
         
    def test_mul(self):
        self.assertEqual([1, 2, 3, 1, 2, 3, 1, 2, 3], self.li_a*3)

    def test_len(self):
        self.assertEqual(3, len(self.li_a))
    
    def test_min(self):
        self.assertEqual(1, min(self.li_a))

    def test_max(self):
        self.assertEqual(3, max(self.li_a))

    def test_silcing(self):
        self.li_a = self.li_a *3
        self.assertEqual(self.li_a[2:5], [3, 1, 2])
        self.assertEqual(self.li_a[::-3], [3, 3, 3])

    def test_index(self):
        self.assertEqual(self.li_a.index(2), 1)

    def test_count(self):
        self.li_a = self.li_a * 3
        self.assertEqual(self.li_a.count(2), 3)

        # ----------以上為「序列」之共同操作----------
        # ----------以下為「可變序列」之共同操作----------

    def test_replace(self):
        self.li_a[1] = 3
        self.assertEqual(self.li_a, [1, 3, 3])

    def test_del(self):
        del self.li_a[1]
        self.assertEqual(self.li_a, [1, 3])

    def test_replace(self):
        self.li_a[1] = 3
        self.assertEqual(self.li_a, [1, 3, 3])

    def test_append(self):
        self.li_a.append(4)
        self.assertEqual(self.li_a, [1, 2, 3, 4])

    def test_extend(self):
        self.li_a.extend(self.li_b)
        self.assertEqual(self.li_a, [1, 2, 3, 4, 5, 6])

    def test_clear(self):
        self.li_a.clear()
        self.assertEqual(self.li_a, [])

    def test_insert(self):
        self.li_a.insert(1, 4)
        self.assertEqual(self.li_a, [1, 4, 2, 3])

    def test_pop(self):
        pop_c = self.li_a.pop(1)
        self.assertEqual(pop_c, 2)
        self.assertEqual(self.li_a, [1, 3])

    def test_remove(self):
        self.li_a.remove(1)
        self.assertEqual(self.li_a, [2, 3])
        # 如同del self.li_a[self.li_a.index(1)]
        # 直接移除那樣東西

    def test_reverse(self):
        self.li_a.reverse()
        self.assertEqual(self.li_a, [3, 2, 1])

    def test_sort(self):
        self.li_a = {1, 5, 4, 3, 2}
        # sorted(self.li_a) = self.li_a.sort()
        self.assertEqual(self.li_a, {1, 2, 3, 4, 5})
