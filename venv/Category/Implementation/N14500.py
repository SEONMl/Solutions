# 제출 pypy
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
middle=[[[0, 1], [0, 2], [-1, 1]], [[0, 1], [0, 2], [1, 1]],
[[1, 0], [2, 0], [1, 1]], [[1, 0], [1, -1], [2, 0]]]
def dfs(a,b,d,res):
    global mmax
    if d==4:
        mmax=max(mmax,res)
        return
    for i in range(4):
        nx,ny=a+dx[i],b+dy[i]
        if 0<=nx<n and 0<=ny<m and not visit[nx][ny]:
            visit[nx][ny]=1
            dfs(nx,ny,d+1,res+g[nx][ny])
            visit[nx][ny]=0

def other(x,y): # ㅗ 모양
    global mmax
    for i in middle:
        try:
            num=g[x][y]+g[x+i[0][0]][y+i[0][1]]+g[x+i[1][0]][y+i[1][1]]+g[x+i[2][0]][y+i[2][1]]
        except:
            num=0
        mmax=max(mmax,num)

mmax=0
visit=[[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        visit[i][j]=1
        dfs(i,j,1,g[i][j])
        other(i,j)
        visit[i][j]=0
print(mmax)