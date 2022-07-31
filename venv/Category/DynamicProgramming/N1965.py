import sys
input=sys.stdin.readline
N=int(input())
a=list(map(int,input().split()))
dp=[[1,0]]*N
dp[0][1]=a[0]
for i in range(1,N):
    dp[i]=[1,a[i]]
    for j in range(i):
        if dp[j][1]<dp[i][1]:
            dp[i][0]=max(dp[j][0]+1,dp[i][0])
print(max(dp)[0])