class Solution:
    def numWaterBottles(self, n: int, ex: int) -> int:
        e = 0
        f = n
        ans = 0
        while(f>0):
            ans = ans + f
            e = e + f
            f = (e)//ex
            e = e % ex
        return ans
