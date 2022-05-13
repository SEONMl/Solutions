import sys
n,k=map(int,input().split())
a=[int(input()) for i in range(n)]
dp=[0]*(k+1)
for i in range(1,k+1):
    tmp=sys.maxsize
    for j in a:
        if i-j>=0:
            tmp=min(tmp,dp[i-j])
    dp[i]=tmp+1

if dp[k]==sys.maxsize+1:
    print(-1)
else:
    print(dp[k])