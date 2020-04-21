import unittest
import copy

class TestFunction(unittest.TestCase):
    def setUp(self):
        self.str_a = 'hELLo'
        self.str_b = 'hello'
        self.str_c = 'HELLO'
        self.str_sentence = 'ThIs iS a sEnTeNcE'

    def test_capitalize(self):
        self.assertEqual(self.str_a.capitalize(), 'Hello')
        self.assertEqual(self.str_sentence.capitalize(), 'This is a sentence')
        
    def test_upper(self):
        self.assertEqual(self.str_a.upper(), 'HELLO')

    def test_lower(self):
        self.assertEqual(self.str_a.lower(), 'hello')

    def test_swapcase(self):
        self.assertEqual(self.str_a.swapcase(), 'HellO')
    # 大寫變小寫，小血變大寫

    def test_title(self):
        self.assertEqual(self.str_sentence.title(), 'This Is A Sentence')
    # 主題式大寫，把space後的每個字都變成大寫（每字首開頭）

    # ----------以上大小寫轉換----------
    # ----------以下內容判斷式----------

    def test_islower(self):
        self.assertTrue(self.str_b.islower())

    def test_upper(self):
        self.assertTrue(self.str_c.isupper())

    def test_istitle(self):
        self.assertTrue(self.str_sentence.title().istitle())

    def test_isspeac(self):
        str_space = ' '
        self.assertTrue(str_space.isspace())
    # 是否只有空白，長度至少為1

    def test_isalpha(self):
        self.assertTrue(self.str_b.isalpha())
    # 是否只有字母，長度至少為1 
   
    def test_isdigit(self):
        str_digit = '123'
        self.assertTrue(str_digit.isdigit())
    # 是否只有字母，長度至少為1
    
    def test_isdecimal(self):
        str_decimal = '123'
        self.assertTrue(str_decimal.isdecimal())
    # 是否只有10進位數字，長度至少為1  （沒有abcde）

    def test_isdigit(self):
        str_digit = '123'
        self.assertTrue(str_digit.isdigit())
    # 是否只有字母，長度至少為1 

    def test_isalnum(self):
        str_alnum = '123abc'
        self.assertTrue(str_alnum.isalnum())
    # 是否只有字母與數字，長度至少為1 

    def test_identifier(self):
        str_identifier = 'list'
        self.assertTrue(str_identifier.isidentifier())
    # 是否只有字母，長度至少為1 

    # ----------以上內容判斷式----------
    # ----------以下子字串 ----------