class Solution:
    def defanging(self, str):
        temp = str.replace(".", "[.]", 3)
        return temp