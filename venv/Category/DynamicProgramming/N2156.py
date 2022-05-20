import sys
input=sys.stdin.readline
n=int(input())
a=[int(input()) for i in range(n)]
# dp[i]= max(dp[i-1],dp[i-3]+a[i-1]+a[i],dp[i-3]+a[i-2]+a[i])
if n==1:
    print(a[0])
    exit(0)
elif n==2:
    print(a[0]+a[1])
    exit(0)
dp=[0]*n
dp[0]=a[0]
dp[1]=a[0]+a[1]
dp[2]=max(dp[1],a[1]+a[2],dp[0]+a[2])
for i in range(3,n):
    dp[i]=max(dp[i-1],dp[i-3]+a[i-1]+a[i],dp[i-2]+a[i])
print(dp)
print(max(dp))