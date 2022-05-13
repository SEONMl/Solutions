# 220513
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10000000)
n,m=map(int,input().split())
dx=[1,-1,0,0]
dy=[0,0,1,-1]
g=[]
for i in range(m):
    tmp=list(map(str,' '.join(input()).split()))
    g.append(tmp)
def dfs(arr,x,y,k):
    global cnt
    if 0<=x<m and 0<=y<n and arr[x][y]==k:
        cnt+=1
        arr[x][y]="-"
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            dfs(arr,nx,ny,k)
        return True
    return False
res=[0,0] # resW=resB=[] 로 선언하니까 얕은복사 일어나서 같은 메모리 공간 ㅅ씀
for i in range(m):
    for j in range(n):
        cnt=0
        if dfs(g,i,j,"W"):
            res[0]+=cnt*cnt
        cnt=0
        if dfs(g,i,j,"B"):
            res[1]+=cnt*cnt
print(*res)