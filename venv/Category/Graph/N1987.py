# 파이썬과 dfs는 상성 최악 ^.^
import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline
n,m=map(int,input().split())
g=[list(input()) for i in range(n)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def dfs(x,y,t):
    global s,mmax

    mmax=max(mmax,t)

    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx<n and 0<=ny<m and not g[nx][ny] in s:
            s.add(g[nx][ny])
            dfs(nx,ny,t+1)
            s.remove(g[nx][ny])

s=set()
s.add(g[0][0])
mmax=0
dfs(0,0,1)
print(mmax)