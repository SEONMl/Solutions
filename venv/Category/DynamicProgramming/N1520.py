# 내 건 왜 시간초과... 똑같은데....
# dp 0으로 초기화 했을 때 시간초과, -1,-2로 초기화하면 시간초과 나지 않음
# 무슨 차이지...
import sys
sys.setrecursionlimit(100000000)
input=sys.stdin.readline

def dfs(x,y):
    if x==n-1 and y==m-1:
        return 1
    if dp[x][y]!=-1:
        return dp[x][y]

    ways=0
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<m and g[nx][ny]<g[x][y]:
            ways+=dfs(nx,ny)

    dp[x][y]=ways
    return dp[x][y]

n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
dp=[[-1]*m for i in range(n)]

print(dfs(0,0))

for i in range(n):
    print(*dp[i])