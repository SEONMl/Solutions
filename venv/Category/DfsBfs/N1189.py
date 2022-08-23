import sys;input=sys.stdin.readline
R,C,K=map(int,input().split())
g=[input().rstrip() for i in range(R)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
ans=0
def dfs(x,y,cnt):
    global ans
    if cnt>=K-1:
        if x==0 and y==C-1:
            ans+=1
        return
    for k in range(4):
        nx,ny=x+dx[k],y+dy[k]
        if 0<=nx<R and 0<=ny<C and g[nx][ny]!="T" and not visit[nx][ny]:
            visit[nx][ny]=1
            dfs(nx,ny,cnt+1)
            visit[nx][ny]=0
visit=[[0]*C for i in range(R)]
visit[R-1][0]=1
dfs(R-1,0,0)
print(ans)