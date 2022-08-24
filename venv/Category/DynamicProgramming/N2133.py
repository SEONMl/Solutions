n=int(input())
dp=[0]*(n+2)
dp[0]=1
dp[2]=3
if n%2:
    print(0)
    exit(0)
for i in range(4,n+1,2):
    dp[i]=dp[i-2]*dp[2]
    for j in range(4,i,2):
        dp[i]+=2*dp[i-j]
    dp[i]+=2
print(dp[n])