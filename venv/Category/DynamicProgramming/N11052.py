import sys
input=sys.stdin.readline
N=int(input())
a=[0]+list(map(int,input().split()))
dp=[0]*(N+1)
dp[1]=a[0]
for i in range(1,N+1):
    for j in range(1,i+1):
        dp[i]=max(dp[i],dp[i-j]+a[j])
print(dp[N])