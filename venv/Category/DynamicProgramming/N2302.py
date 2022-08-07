import sys
input=sys.stdin.readline
n=int(input())  # 1<=n<=40
m=int(input())
a=[int(input()) for i in range(m)]
dp=[1]*(n+1)
dp[1]=1
for i in range(2,n+1):
    dp[i]=dp[i-1]+dp[i-2]
res=1
tmp=1
for i in range(1,n+1):
    if i in a:
        res*=dp[tmp-1]
        tmp=1
    else:
        tmp+=1
res*=dp[tmp-1]
print(res)