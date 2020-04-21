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

    # 字典生成式

    def test_generate(self):
        temp_1 = dict.fromkeys(self.li_1)
        self.assertEqual(temp_1, {'a': None, 'b': None, 'c':None})
        temp_2 = dict.fromkeys(self.li_1, 1)
        self.assertEqual(temp_2, {'a': 1, 'b': 1, 'c': 1})

    def test_generate2(self):
        temp_1 = {k:k**2 for k in range(5)}
        self.assertEqual(temp_1, {0:0, 1:1, 2:4, 3:9, 4:16})
        temp_2 = {k:k**2 for k in range(5) if k**2 > 3}
        self.assertEqual(temp_2, {2:4, 3:9, 4:16})
        # 若不透過此生成式，只有key可以是iterator
        temp_3 = {a:i for i, a in enumerate(self.li_1, start = 1)}
        self.assertEqual(temp_3, self.dict_1)

    def test_len(self):
        self.assertEqual(len(self.dict_1), 3)

    def test_in_dict(self):
        self.assertTrue('a' in self.dict_1)

    def test_get_1(self):
        self.assertEqual(self.dict_1.get('a'), 1)
 
    def test_get_2(self):
        self.assertEqual(self.dict_1.get('d', 'none'), 'none') 

    def test_setdeafault_1(self):
        self.assertEqual(self.dict_1.setdefault('a'), 1)
 
    def test_setdafault_2(self):
        self.assertEqual(self.dict_1.setdefault('d'), None) 

    def test_pop_(self):
        self.assertEqual(self.dict_1.pop('a'), 1)
        self.assertEqual(self.dict_1.setdefault('a'), None)
 
    def test_popitem_(self):
        self.dict_1.popitem()
        self.dict_1.popitem()
        self.dict_1.popitem()
        self.assertEqual(self.dict_1.setdefault('a'), None)

    def test_update_1(self):
        self.dict_1.update(self.dict_2)
        self.assertEqual(self.dict_1, {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6})

    def test_update_2(self):
        self.dict_1.update({'d' : 4, 'e' : 5, 'f' : 6})
        self.assertEqual(self.dict_1, {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6})

    def test_clear(self):
        self.assertEqual(self.dict_1.clear(), None)

    def test_keys(self):
        self.assertEqual(list(self.dict_1.keys()), ['a', 'b', 'c'])
    # 出來的物件是dict_keys（一種映射物件）, 要轉list才能用
    def test_values(self):
        self.assertEqual(list(self.dict_1.values()), [1, 2, 3])
    # 出來的物件是dict_values（一種映射物件）, 要轉list才能用
    def test_items(self):
        self.assertEqual(list(self.dict_1.items()), [('a',1), ('b', 2), ('c', 3)])
    # 出來的物件是dict_items（一種映射物件）, 要轉list才能用