n=int(input())
# n 1. n//=2 2. n//=3 3. n-=1
# n=1 : 0
# n=2 : 1
# n=3 : 1
# n=4 : 2 (4->2->1)
# n=5 : 3
# n=6 : 2
# n=10 : (10->5->4->2->1) (10->9->3->1)
dp=[0]*(n+1)
for i in range(2,n+1):
    dp[i] = dp[i-1]+1
    if i%3==0:
        dp[i]=min(dp[i//3]+1,dp[i])
    if i%2==0:
        dp[i]=min(dp[i//2]+1,dp[i])
print(dp[n])
'''
이건 왜 IndexError?
n=int(input())
dp=[0]*(n+1)
dp[2]=1
dp[3]=1
for i in range(4,n+1):
    dp[i] = dp[i-1]+1
    if i%3==0:
        dp[i]=min(dp[i//3]+1,dp[i])
    if i%2==0:
        dp[i]=min(dp[i//2]+1,dp[i])
print(dp[n])
'''