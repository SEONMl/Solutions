# 220510
from collections import deque
import sys
n, m, v = map(int, sys.stdin.readline().split())
matrix = [[]*(n+1) for i in range(n+1)];

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    matrix[a].append(b)
    matrix[b].append(a)

def dfs(v):
    global res,visit
    res.append(v)
    visit[v]=1
    for i in sorted(matrix[v]):
        if visit[i]!=1:
            dfs(i)
def bfs(v):
    global res,visit
    visit[v]=1
    q=deque()
    q.append(v)
    while q:
        tmp=q.popleft()
        for i in sorted(matrix[tmp]):
            if visit[i]!=1:
                visit[i]=1
                q.append(i)
        res.append(tmp)

res=[]
visit = [0]*(n+1)
dfs(v)
print(*res)

res=[]
visit = [0]*(n+1)
bfs(v)
print(*res)