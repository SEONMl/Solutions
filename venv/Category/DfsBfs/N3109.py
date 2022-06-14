# 음... dx 순서가 정답에 영향을 미침
r,c=map(int,input().split())
g=[list(input()) for i in range(r)]
visit=[[0]*c for i in range(r)]
dx=[-1,0,1]
cnt=0
def dfs(x,y):
    global cnt
    if y==c-1:
        cnt+=1
        return True
    for i in range(3):
        nx=x+dx[i]
        ny=y+1
        if 0<=nx<r and 0<=ny<c and g[nx][ny]!="x" and visit[nx][ny]==0:
            visit[nx][ny]=1
            if dfs(nx,ny):
                return True
    return False

for i in range(r):
    dfs(i,0)
print(cnt)