import unittest
import math

class TestFunction(unittest.TestCase):
    # def setUp(self):

    def test_type(self):
        a = 0b1100100
        b = 0x64
        c = 0o144
        self.assertEqual(a, 100)
        self.assertEqual(b, 100)
        self.assertEqual(c, 100)

    def test_other_type_to_dec(self):
        # 最主要是換成字串用
        a = bin(100)
        b = oct(100)
        c = hex(100)
        self.assertEqual(a, '0b1100100')
        self.assertEqual(b, '0o144')
        self.assertEqual(c, '0x64')

    def test_inf_nan(self):
        #inf是指infinity,nan是指無理數
        a = float('nan')
        b = float('inf')
        c = float('-inf')
        d = 0
        self.assertTrue(math.isnan(a))
        self.assertTrue(math.isinf(b))
        self.assertTrue(math.isinf(c))
        self.assertTrue(math.isfinite(d))

    def test_round(self):
        a = 2.5
        b = -2.5
        self.assertEqual(round(a), 2.0)
        self.assertEqual(round(b), -2.0)
        # 靠向偶數

    # P.97, Decimal用法
    # P.100, Fraction用法

    def test_BCD(self):
        exc = 1*(2**7) +1*(2**6) + 1*(2**5) + 1*(2**4) + 1*(2**3) + 1*(2**2) + 1*(2**1) + 0*(2**0)
        # 11111110
        self.assertEqual(exc, 254)

    # and &
    # or |
    # xor ^
    
    def test_get_bits(self):
        exc = getbits(0b11110101, 5, 4)
        self.assertEqual(exc, 0b1101)

    # 取出binary的指定位數
def getbits(x, p, n):
    #從第p位向右拿出n個位元
    return(x >> (p+1-n))& ~(~0b0 << n) 
