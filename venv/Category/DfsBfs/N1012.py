import sys
sys.setrecursionlimit(10000)
c=int(input())
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def dfs(x,y,m,n):
    if x>=m or y>=n or x<0 or y<0:
        return False
    if a[y][x]==1:
        a[y][x]=0
        for i in range(4):
            dfs(x+dx[i], y+dy[i],m,n)
        return True
    return False

for i in range(c):
    m,n,k=map(int, input().split())
    a=[[0] * m for _ in range(n)]
    cnt=0
    for _ in range(k):
        p,q=map(int, input().split())
        a[q][p]=1
    for x in range(m):
        for y in range(n):
            if dfs(x,y,m,n)==True:
                cnt+=1
    print(cnt)

