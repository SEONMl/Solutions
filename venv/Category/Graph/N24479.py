# 220508 | dfs 스택 구현
import sys
sys.setrecursionlimit(1000000)
n,m,r=map(int,input().split())
g=[[]*(n+1) for i in range(n+1)]
visit=[0]*(n+1)
for i in range(m):
    a,b=map(int,input().split())
    g[a].append(b)
    g[b].append(a)
res=[0]*n
stk=[r]
depth=1
for i in range(n+1):
    g[i].sort(reverse=True)

while stk:
    cur=stk.pop()
    visit[cur]=1
    if res[cur-1]==0:
        res[cur-1]=depth
    for i in g[cur]:
        if not visit[i]:
            stk.append(i)
    depth+=1
print(*res)