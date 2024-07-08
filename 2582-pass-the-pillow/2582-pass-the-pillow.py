class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        k = 1
        dir = 0
        while(time):
            time = time - 1
            if(k == n):
                dir = 1
            elif(k == 1):
                dir = 0
            
            if(dir == 0):
                k = k+1
            else:
                k = k - 1
        return k
