# DP
def solution(triangle):
    n=len(triangle)
    dp=[[0]*n for i in range(n)]
    dp[0][0]=triangle[0][0]
    for i in range(1,n):
        for j in range(i+1):
            if j==0:
                dp[i][j]=triangle[i][j]+dp[i-1][j]
            elif j==i:
                dp[i][j]=triangle[i][j]+dp[i-1][j-1]
            elif 0<j and j<i:
                dp[i][j]=triangle[i][j]+max(dp[i-1][j-1],dp[i-1][j])
    return max(dp[n-1])

t=[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]
print(solution(t))