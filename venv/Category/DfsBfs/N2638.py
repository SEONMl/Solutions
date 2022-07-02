import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
def bfs(a,b):
    global EXIST
    exposed=[[0]*m for i in range(n)]
    q=deque()
    q.append((a,b))
    visit[a][b]=1
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<m and not visit[nx][ny]:
                if g[nx][ny]==0:
                    q.append((nx,ny))
                    visit[nx][ny]=1
                else:
                    EXIST=True
                    exposed[nx][ny]+=1
    for i in range(n):
        for j in range(m):
            if exposed[i][j]>=2:
                visit[i][j]=1
                g[i][j]=0

hour=0
while 1:
    visit=[[0]*m for i in range(n)]
    EXIST=False
    bfs(0,0)
    if not EXIST:
        print(hour)
        exit(0)
    hour+=1