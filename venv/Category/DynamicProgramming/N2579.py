n=int(input())
s=[int(input()) for i in range(n)]
# dp는 점화식
# 마지막 전 계단을 밟(전전계단x) or 마지막 전전계딴을 밟(
# dp[n]=dp[n-3]+s[n]+s[n-1]
# dp[n]=dp[n-2]+s[n]
dp=[0]*n # idx+1 번째 계단을 올라 갔을 때의 최댓값
if n==1:
    print(s[0])
    exit(0)
elif n==2:
    print(s[0]+s[1])
    exit(0)
dp[0]=s[0]
dp[1]=s[0]+s[1]
dp[2]=max(s[0]+s[2], s[1]+s[2])
for i in range(3,n):
    dp[i]=max(dp[i-3]+s[i]+s[i-1], dp[i-2]+s[i])
print(dp[n-1])
