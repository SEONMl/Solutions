# 시간 더 줄일 수 있음 - 어떻게? 나중에~
import sys
from collections import deque
n=int(input()) # 2<=n<=1000
dp=[[-1]*(n+1) for i in range(n+1)] # dp[게시판임티개수][클립보드개수]=시간

q=deque()
q.append([1,0])
dp[1][0]=0

# 붙여넣기 dp[s+c][c]=dp[s][c]+1
# 카피 dp[s][s]=dp[s][c]+1
# 삭제 dp[s-1][c]=dp[s][c]+1
while q:
    s,c=q.popleft()
    if dp[s][s]==-1: # 방문하지 않았음
        dp[s][s]=dp[s][c]+1
        q.append([s,s])
    if s+c<=n and dp[s+c][c]==-1:
        dp[s+c][c]=dp[s][c]+1
        q.append([s+c,c])
    if 2<=s-1 and dp[s-1][c]==-1:
        dp[s-1][c]=dp[s][c]+1
        q.append([s-1,c])

res=sys.maxsize
for i in range(1,n+1):
    if dp[n][i]!=-1:
        res=min(dp[n][i],res)
print(res)