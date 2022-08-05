import sys
input=sys.stdin.readline
N=int(input())
a=list(map(int,input().split()))
# 실력차이 많이 나게
dp=[0]*(N+1)
for i in range(1,N+1):
    mx=-sys.maxsize
    mn=sys.maxsize
    for j in range(i,0,-1):
        mx=max(mx,a[j-1])
        mn=min(mn,a[j-1])
        dp[i]=max(dp[i],dp[j-1]+mx-mn)
print(dp[N])