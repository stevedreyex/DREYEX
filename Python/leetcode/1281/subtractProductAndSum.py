class Solution(object):
    def subtractProductAndSum(self, n: int) -> int:
        sum = 0
        mul = 1
        while n:
            num = n % 10
            n //= 10
            sum += num
            mul *= num
        return mul - sum
