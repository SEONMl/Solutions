import sys;input=sys.stdin.readline
N=int(input())
a=[list(map(int,input().split())) for i in range(N)]
dp=[0]*(N+1)
for i in range(N-1,-1,-1):
    if a[i][0]+i>N:
        dp[i]=dp[i+1]
    else:
        dp[i]=max(dp[i+1],a[i][1]+dp[i+a[i][0]])
print(dp[0])