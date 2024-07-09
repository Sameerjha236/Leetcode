class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        ans, t, i = 0, customers[0][0], 0
        n = len(customers)
        while i < n:
            a, tm = customers[i][0], customers[i][1]
            if t > a:
                ans += t - a
            else:
                t = a
            ans += tm
            t += tm
            i += 1

        return ans / n
