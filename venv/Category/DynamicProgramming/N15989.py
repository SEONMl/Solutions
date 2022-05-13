# 220513 | 점화식은 한 줄 만으로 표현되지 않을 수 있다.
import sys
input=sys.stdin.readline
n=int(input())
a=[int(input()) for i in range(n)]
N=max(a)
dp=[1]*(N+1) # 1로 구성된 테이블 하나씩 갖고 있기 때문
for i in range(2,N+1):
    dp[i]+=dp[i-2]
for i in range(3,N+1):
    dp[i]+=dp[i-3]
for i in range(n):
    print(dp[a[i]])