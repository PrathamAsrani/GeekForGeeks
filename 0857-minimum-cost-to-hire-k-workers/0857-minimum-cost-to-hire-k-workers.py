import heapq as pq

class Pair:
    def __init__(self, ratio, qua):
        self.ratio = ratio
        self.qua = qua

class Solution:
    def mincostToHireWorkers(self, q: List[int], w: List[int], k: int) -> float:
        n = len(q)
        ratios = [Pair(w[i]/q[i], q[i]) for i in range(n)]
        ratios.sort(key = lambda x: x.ratio)
        ans, qua_sum = float('inf'), 0
        arr = []
        for x in ratios:
            ratio = x.ratio
            qua_sum += x.qua
            pq.heappush(arr, -x.qua)
            if len(arr) > k:
                qua_sum += pq.heappop(arr)
            if len(arr) == k:
                ans = min(ans, qua_sum * ratio)
        return ans
