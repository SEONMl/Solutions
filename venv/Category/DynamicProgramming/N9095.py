import sys
input=sys.stdin.readline
n=int(input())
a=[int(input()) for i in range(n)]
N=max(a)
dp=[0]*(N+1)
dp[1]=1
dp[2]=2
dp[3]=4
for i in range(4,N+1):
    dp[i]=dp[i-3]+dp[i-2]+dp[i-1]
for i in range(n):
    print(dp[a[i]])