import sys;S=sys.stdin.readline().rstrip()
N=len(S)
dp=[0]*(N+1)
# 1,000,000 으로 나눈 나머지
if S[0]=='0':
    print(0)
    exit(0)
dp[0]=dp[1]=1
for i in range(2,N+1):
    if int(S[i-1])>0: # 바보.....
        dp[i]+=dp[i-1]
    if 10<=int(S[i-2]+S[i-1])<=26:
        dp[i]+=dp[i-2]
print(dp[N]%1000000)