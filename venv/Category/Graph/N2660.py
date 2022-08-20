import sys;input=sys.stdin.readline
from collections import deque
N=int(input())
g=[[] for i in range(N+1)]
while 1:
    a,b=map(int,input().split())
    if a==-1 and b==-1:
        break
    g[a].append(b)
    g[b].append(a)
def bfs(s):
    q=deque()
    q.append((s,0))
    visit=[0]*(N+1)
    visit[s]=1
    while q:
        tmp,cnt=q.popleft()
        for i in g[tmp]:
            if not visit[i]:
                visit[i]=1
                q.append((i,cnt+1))
    return cnt
ans=[]
for i in range(1,N+1):
    ans.append(bfs(i))
minest=min(ans)
candidates=[i+1 for i in range(i) if ans[i]==minest]
print(minest, len(candidates))
print(*candidates)