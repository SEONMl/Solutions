from collections import deque
import sys
m,n,h=map(int,input().split())
g=[]
q=deque()

dx=(1,-1,0,0,0,0)
dy=(0,0,1,-1,0,0)
dz=(0,0,0,0,1,-1)
for i in range(h):
    tmp=[]
    for j in range(n):
        tmp.append(list(map(int, sys.stdin.readline().split())))
        for k in range(m):
            if tmp[j][k]==1:
                q.append((i,j,k))
    g.append(tmp)

def bfs():
    while q:
        x,y,z=q.popleft()
        for i in range(6):
            nx=x+dx[i]
            ny=y+dy[i]
            nz=z+dz[i]
            if 0<=nx<h and 0<=ny<n and 0<=nz<m and g[nx][ny][nz]==0:
                q.append((nx,ny,nz))
                g[nx][ny][nz]=g[x][y][z]+1
bfs()
cnt=0
for i in g:
    for j in i:
        for k in j:
            if k==0:
                print(-1)
                exit(0)
        cnt=max(cnt,max(j))
print(cnt-1)