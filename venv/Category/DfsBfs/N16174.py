import sys;input=sys.stdin.readline
from collections import deque
N=int(input())
g=[list(map(int,input().split())) for i in range(N)]
dx=[1,0]
dy=[0,1]
def dfs():
    q=deque()
    q.append((0,0))
    visit=[[0]*N for i in range(N)]
    while q:
        x,y=q.popleft()
        if g[x][y]==-1:
            return True
        for i in range(2):
            nx,ny=x+dx[i]*g[x][y],y+dy[i]*g[x][y]
            if 0<=nx<N and 0<=ny<N and not visit[nx][ny]:
                q.append((nx,ny))
                visit[nx][ny]=1
if dfs():
    print("HaruHaru")
else:
    print("Hing")