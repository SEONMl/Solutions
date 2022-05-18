from collections import deque
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
dx=[-1,-1,-1,0,0,1,1,1]
dy=[1,0,-1,1,-1,1,0,-1]
q=deque()
for i in range(n):
    for j in range(m):
        if g[i][j]==1:
            q.append([i,j])
res=0
while q:
    i,j=q.popleft()
    for k in range(8):
        nx=i+dx[k]
        ny=j+dy[k]
        if 0<=nx<n and 0<=ny<m and not g[nx][ny]:
            g[nx][ny]=g[i][j]+1
            res=max(res,g[i][j])
            q.append([nx,ny])
print(res)
