import sys
from collections import deque
input=sys.stdin.readline
N,L,R=map(int,input().split()) # 이상 이하
g=[list(map(int,input().split())) for i in range(N)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
day=0
def bfs(a,b):
    global visit,g,didMoved
    q=deque()
    q.append([a,b])
    adj=[[a,b]]
    visit[a][b]=1
    while q:
        i,j=q.popleft()
        for k in range(4):
            nx=i+dx[k]
            ny=j+dy[k]
            if 0<=nx<N and 0<=ny<N and visit[nx][ny]==0:
                if L<=abs(g[nx][ny]-g[i][j])<=R:
                    visit[nx][ny]=1
                    q.append([nx,ny])
                    adj.append([nx,ny])

    if len(adj)>1:
        tmp=sum(g[x][y] for x,y in adj)//len(adj)
        for i,j in adj:
            didMoved=True
            g[i][j]=tmp

while 1:
    visit=[[0]*N for i in range(N)]
    didMoved=False
    for i in range(N):
        for j in range(N):
            if visit[i][j]==0:
                bfs(i,j)

    if not didMoved:
        print(day)
        exit(0)
    else:
        day+=1