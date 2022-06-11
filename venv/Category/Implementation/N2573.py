import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
visit=[[0]*m for i in range(n)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
def melting():
    cnt = [[0] * m for _ in range(n)]
    for i in range(1,n-1):
        for j in range(1,m-1):
            if g[i][j]>0:
                for k in range(4):
                    nx=i+dx[k]
                    ny=j+dy[k]
                    if g[nx][ny]<=0:
                        cnt[i][j]+=1
    for i in range(1,n-1):
        for j in range(1,m-1):
            g[i][j]-=cnt[i][j]
def bfs(x,y):
    global visit
    q=deque()
    q.append((x,y))
    visit[x][y]=1
    while q:
        tx,ty=q.popleft()
        for i in range(4):
            nx=tx+dx[i]
            ny=ty+dy[i]
            if visit[nx][ny]==0 and g[nx][ny]>0:
                q.append((nx,ny))
                visit[nx][ny]=1
year=0
while 1:
    cnt=0
    visit = [[0] * m for i in range(n)]
    for i in range(1,n-1):
        for j in range(1,m-1):
            if g[i][j]>0 and visit[i][j]==0:
                bfs(i,j)
                cnt+=1
    if cnt>1:
        print(year)
        break
    if cnt==0:
        print(0)
        break
    year+=1
    melting()
