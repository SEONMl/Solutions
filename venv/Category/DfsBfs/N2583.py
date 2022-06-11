from collections import deque
n,m,k=map(int,input().split())
g=[[0]*m for i in range(n)]
visit=[[0]*m for i in range(n)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
def bfs(x,y):
    q=deque()
    q.append((x,y))
    visit[y][x]=1
    cnt=1
    while q:
        tx,ty=q.popleft()
        for i in range(4):
            nx=tx+dx[i]
            ny=ty+dy[i]
            if 0<=nx<m and 0<=ny<n and g[ny][nx]==0 and visit[ny][nx]==0:
                q.append((nx,ny))
                visit[ny][nx]=1
                cnt+=1
    return cnt
for _ in range(k):
    x1,y1,x2,y2=map(int,input().split())
    for i in range(x1,x2):
        for j in range(y1,y2):
            g[j][i]=1
res=[]
for i in range(n):
    for j in range(m):
        if g[i][j]==0 and visit[i][j]==0:
            res.append(bfs(j,i))
res.sort()
print(len(res))
print(*res)