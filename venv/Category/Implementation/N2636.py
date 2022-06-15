# 외곽선 딸 때, 밖에서부터 따는 방법도 생각해 보기
import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split()) # n*m
g=[list(map(int,input().split())) for i in range(n)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def bfs(a,b):
    q=deque()
    q.append((a,b))
    visit[a][b]=1
    cnt=0
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<n and 0<=ny<m and not visit[nx][ny]:
                if g[nx][ny]==0:
                    visit[nx][ny]=1
                    q.append((nx,ny))
                else:
                    visit[nx][ny]=1
                    g[nx][ny]=0
                    cnt+=1
    return cnt
hour=0
prev=0
while 1:
    visit=[[0]*m for i in range(n)]
    cnt=bfs(0,0)
    if cnt==0:
        print(hour)
        print(prev)
        exit(0)
    else:
        hour+=1
        prev=cnt
