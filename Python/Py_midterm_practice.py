import unittest
import re
import math


class TestStringType(unittest.TestCase):
    # 以下string類別
    def test_split1(self):
        str = 'This is a book'
        list = str.split()
        self.assertEqual(list[0], 'This')
        self.assertEqual(list[1], 'is')
        self.assertEqual(list[2], 'a')
        self.assertEqual(list[3], 'book')

    def test_split2(self):
        str = "this is string example....wow!!!"
        exc1 = str.split('i', 1)
        exc2 = str.split('w')
        self.assertEqual(exc1, ['th', 's is string example....wow!!!'])
        self.assertEqual(exc2, ['this is string example....', 'o', '!!!'])

    def test_strip(self):
        # 只移頭尾歐 ^ ^ 沒辦法萬能移除那麼op
        # default為移除空格
        str = '123abcde321'
        temp = str.strip('123')
        self.assertEqual(temp, 'abcde')

    def test_rstrip(self):
        # 只移尾巴歐
        str = '123abcde321'
        temp = str.rstrip('321')
        self.assertEqual(temp, '123abcde')

    def test_re_split(self):
        exc1 = re.split(r';', 'aaa bbb ccc;ddd   eee,fff')
        # 單字符切割
        exc2 = re.split(r'[;,]', 'aaa bbb ccc;ddd   eee,fff')
        # 多字符切割
        exc3 = re.split(r'[;,\s]', 'aaa bbb ccc;ddd\teee,fff')
        # \s是所有空白類型字元
        exc4 = re.split(r'([;])', 'aaa bbb ccc;ddd   eee,fff')
        # 把([])內的東西獨立切出來
        exc5 = re.split(r'(?:[;])', 'aaa bbb ccc;ddd   eee,fff')
        # 與上一部相似，但;被殺掉了QAQ
        self.assertEqual(exc1, ['aaa bbb ccc', 'ddd   eee,fff'])
        self.assertEqual(exc2, ['aaa bbb ccc', 'ddd   eee', 'fff'])
        self.assertEqual(exc3, ['aaa', 'bbb', 'ccc', 'ddd', 'eee', 'fff'])
        self.assertEqual(exc4, ['aaa bbb ccc', ';', 'ddd   eee,fff'])
        self.assertEqual(exc5, ['aaa bbb ccc', 'ddd   eee,fff'])
# 以下list類別

    def test_remove(self):
        ls = [123, 'abc', 456]
        ls.remove('abc')
        self.assertEqual(ls, [123, 456])

    def test_sort(self):
        ls = [1, 3, 4, 5, 2]
        # list.sort(cmp=None, key=None, reverse=False)
        ls.sort(key=lambda a: abs(a-4), reverse=True)
        self.assertEqual(ls, [1, 2, 3, 5, 4])
# 以下file類別
    # def test_write(self):

    def test_read(self):
        f = open('book.txt', 'r')
        self.assertEqual(
            f.read(), 'This is a book\nThat is an apple\nI am handsome.')

    def test_readline(self):
        f = open('book.txt', 'r')
        self.assertEqual(f.readline(), 'This is a book\n')
        # 換行符算在該行!!!

    def test_readlines(self):
        f = open('book.txt', 'r')
        self.assertEqual(
            f.readlines(), ['This is a book\n', 'That is an apple\n', 'I am handsome.'])
