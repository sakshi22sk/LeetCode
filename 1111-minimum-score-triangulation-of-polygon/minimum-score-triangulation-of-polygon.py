class Solution:
    def minScoreTriangulation(self, values):
        n = len(values)
        dp = [[0] * n for _ in range(n)]

        # gap length from 2 upwards
        for length in range(2, n):  
            for i in range(n - length):
                j = i + length
                dp[i][j] = float("inf")
                for k in range(i + 1, j):
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]
                    )

        return dp[0][n - 1]
