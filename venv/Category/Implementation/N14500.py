# 제출 pypy
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def dfs(a,b,d,res):
    global mmax
    if mmax>=res+max_val*(4-d):
        return
    if d==4:
        mmax=max(mmax,res)
        return
    for i in range(4):
        nx,ny=a+dx[i],b+dy[i]
        if 0<=nx<n and 0<=ny<m and not visit[nx][ny]:
            if d==2:
                visit[nx][ny]=1
                dfs(a,b,d+1,res+g[nx][ny])
                visit[nx][ny]=0
            visit[nx][ny]=1
            dfs(nx,ny,d+1,res+g[nx][ny])
            visit[nx][ny]=0

mmax=0
max_val=max(map(max,g))
visit=[[0]*m for i in range(n)]
for i in range(n):
    for j in range(m):
        visit[i][j]=1
        dfs(i,j,1,g[i][j])
        visit[i][j]=0
print(mmax)