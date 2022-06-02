n=int(input())
dp=[0]*(n+1)
if n==1:
    print(1)
    exit(0)
dp[1]=1
dp[2]=2
for i in range(3,n+1):
    dp[i]=dp[i-1]+dp[i-2]
print(dp[n]%10007)
# 2*n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지 출력