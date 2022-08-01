N=int(input())
# 9901로 나눈 나머지
dp=[1]*(N+1)
dp[1]=3
for i in range(2,N+1):
    dp[i]=(dp[i-2]+dp[i-1]*2)%9901
print(dp[N])