# 220508
from collections import deque
n=int(input())
m=int(input())
cnt=0
g=[[] for i in range(n+1)]
visit=[0]*(n+1)
for i in range(m):
    a,b=map(int,input().split())
    g[a].append(b)
    g[b].append(a)

def dfs(start):
    global cnt
    visit[start]=1
    for i in g[start]:
        if visit[i]!=1:
            dfs(i)
            cnt+=1
dfs(1)
print(cnt)