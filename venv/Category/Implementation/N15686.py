import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)
n,m=map(int,input().split())
g=[list(map(int,input().split())) for i in range(n)]
# 0 빈칸, 1 집, 2 치킨집
# m=폐업하지 않을 치킨집 수
chicken=[]
house=[]

for i in range(n):
    for j in range(n):
        if g[i][j]==2:
            chicken.append((i,j))
        elif g[i][j]==1:
            house.append((i,j))
visit=[0]*len(chicken)

def getDistance():
    dis=0
    for i,j in house:
        mmin=2*n
        t=-1
        for x,y in chicken:
            t+=1
            if visit[t]==1:
                continue
            mmin=min(mmin,abs(i-x)+abs(j-y))
        dis+=mmin
    return dis

def dfs(t,k):
    global min_dis
    if k==m:
        min_dis=min(min_dis,getDistance())
        return
    for i in range(t,len(chicken)):
        if visit[i]==0:
            visit[i]=1
            dfs(i,k-1)
            visit[i]=0

min_dis=sys.maxsize
dfs(0,len(chicken))
print(min_dis)

