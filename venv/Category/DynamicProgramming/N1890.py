import sys;input=sys.stdin.readline
N=int(input())
g=[list(map(int,input().split())) for i in range(N)]
dp=[[0]*N for i in range(N)]
dp[0][0]=1
for x in range(N):
    for y in range(N):
        nx,ny=x+g[x][y],y+g[x][y]
        if g[x][y]!=0:
            if 0<=nx<N:
                dp[nx][y]+=dp[x][y]
            if 0<=ny<N:
                dp[x][ny]+=dp[x][y]
print(dp[N-1][N-1])