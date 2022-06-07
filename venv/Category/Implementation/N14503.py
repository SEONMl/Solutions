import sys
input=sys.stdin.readline
n,m=map(int,input().split()) # n*m
r,c,d=map(int,input().split()) # d==0,1,2,3 : 북 동 남 서
g=[list(map(int,input().split())) for i in range(n)] # 북->남 / 서->동
dx=[-1,0,1,0]
dy=[0,1,0,-1]

def dfs(x,y,d):
    global cnt
    if g[x][y]==0:
        g[x][y]=2
        cnt+=1

    for i in range(4):
        if d==0:
            d=4
        nx=x+dx[d-1]
        ny=y+dy[d-1]
        if g[nx][ny]==0:
            dfs(nx,ny,d-1)
            return
        d=d-1
    bx=x+dx[d-2]
    by=y+dy[d-2]
    if g[bx][by]==1:
        return
    else:
        dfs(bx,by,d)

cnt=0
dfs(r,c,d)
print(cnt)
