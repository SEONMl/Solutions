from collections import deque
m,n=map(int,input().split())
g=[]
q=deque([])
dx=(1,-1,0,0)
dy=(0,0,1,-1)
for i in range(n):
    g.append(list(map(int,input().split())))
    for j in range(m):
        if g[i][j]==1:
            q.append((i,j))

def bfs():
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if 0<=nx<n and 0<=ny<m and g[nx][ny]==0:
                q.append((nx,ny))
                g[nx][ny]=g[x][y]+1
bfs()
cnt=0
for i in g:
    for j in i:
        if j==0:
            print(-1)
            exit(0)
    cnt=max(cnt,max(i))
print(cnt-1)