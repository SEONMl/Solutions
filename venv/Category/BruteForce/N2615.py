import sys
N=19
g=[list(map(int,sys.stdin.readline().split())) for i in range(N)]
dx=[1,1,0,-1]
dy=[0,1,1,1]
def bfs(x,y):
    target=g[x][y]
    for k in range(4):
        cnt=1
        nx,ny=x+dx[k],y+dy[k]
        while 0<=nx<N and 0<=ny<N and g[nx][ny]==target:
            cnt+=1
            if cnt==5:
                if 0<=x-dx[k]<N and 0<=y-dy[k]<N and g[x-dx[k]][y-dy[k]]==target:
                    break
                if 0<=nx+dx[k]<N and 0<=ny+dy[k]<N and g[nx+dx[k]][ny+dy[k]]==target:
                    break
                print(target)
                print(x+1,y+1)
                exit(0)
            nx+=dx[k]
            ny+=dy[k]
for i in range(N):
    for j in range(N):
        if g[i][j]!=0:
            bfs(i,j)
print(0)