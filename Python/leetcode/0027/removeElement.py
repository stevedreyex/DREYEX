class Solution(object):
    def removeElement(self, nums, val):
        temp = 0
        ls = nums
        for i in nums:
            if i == val:
                temp += 1
        for i in range(temp):
            ls.remove(val)
        return ls
