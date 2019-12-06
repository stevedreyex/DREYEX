class Solution:
    def reverse(self, x):
        result = 0
        flag =0
        if x <=0:
            temp = -x
            flag = 1
        elif x ==0:
            return 0
        else:
            temp = x
            flag = 0
        while temp != 0:
            result *= 10
            result += (temp % 10)
            temp //= 10
            # please use '//' instead of %
        if result >= pow(2, 31) or result <= -pow(2, 31):
            return 0
        elif flag == 1:
            return -result
        return result

