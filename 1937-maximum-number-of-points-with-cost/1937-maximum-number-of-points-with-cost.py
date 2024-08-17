class Solution:
    def maxPoints(self, mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        prev = [num for num in mat[0]]
        for row in range(1, n):
            curr = [0] * m
            left, right = [0]*m, [0]*m

            left[0] = prev[0]
            for col in range(1, m):
                left[col] = max(left[col-1]-1, prev[col])
            
            right[m-1] = prev[m-1]
            for col in range(m-2, -1, -1):
                right[col] = max(right[col+1]-1, prev[col])
            
            for col in range(0, m):
                curr[col] = max(left[col], right[col]) + mat[row][col]
            
            prev = curr
        return max(prev)

