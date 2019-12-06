class Solution:
    def isPalindrome(self, x):
        result = 0
        flag = 0
        temp = x
        if x < 0:
            return False
        while temp != 0:
            result *= 10
            result += (temp % 10)
            temp //= 10
            # please use '//' instead of %
        if x == result:
            return True
        return False

