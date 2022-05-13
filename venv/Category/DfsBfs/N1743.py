# 220513
import sys
input=sys.stdin.readline
sys.setrecursionlimit(100000000)
n,m,k=map(int,input().split())
g=[[0 for i in range(m+1)] for i in range(n+1)]
for i in range(k):
    r,c=map(int,input().split())
    g[r][c]=1
dx=[1,-1,0,0]
dy=[0,0,1,-1]
res=[]
def dfs(arr,x,y):
    global cnt
    if 0<=x<=n and 0<=y<=m and arr[x][y]==1 :
        cnt+=1
        arr[x][y]=0
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            dfs(arr,nx,ny)
        return True
    return False
for i in range(1,n+1):
    for j in range(1,m+1):
        cnt=0
        if dfs(g,i,j)==True:
            res.append(cnt)
print(max(res))