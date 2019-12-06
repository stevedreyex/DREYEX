class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        j = [char for char in J]
        s = [char for char in S]
        temp = 0
        for x in j:
            for y in s:
                if x==y:
                    temp+=1
        return temp