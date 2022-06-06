# 삼성SW역량
import sys
from collections import deque
input=sys.stdin.readline

n,m=map(int,input().split()) # 3<=n,m<=8
g=[list(map(int,input().split())) for i in range(n)] # 0:빈칸, 1:벽, 2:바이러스
copy_g=[[0]*m for i in range(n)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def virus_dfs(x,y):
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<m and copy_g[nx][ny]==0:
            copy_g[nx][ny]=2
            virus_dfs(nx,ny)

def countZero():
    res=0
    for i in range(n):
        for j in range(m):
            if copy_g[i][j]==0:
                res+=1
    return res
mmax=0
def bfs(count):
    global mmax
    if count==3:
        for i in range(n):
            for j in range(m):
                copy_g[i][j]=g[i][j]
        for i in range(n):
            for j in range(m):
                if copy_g[i][j]==2:
                    virus_dfs(i,j)
        mmax=max(mmax,countZero())
        return

    for i in range(n):
        for j in range(m):
            if g[i][j]==0:
                g[i][j]=1
                bfs(count+1)
                g[i][j]=0

bfs(0)
print(mmax)