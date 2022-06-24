import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
g=[[] for i in range(n+1)]
in_degree=[0]*(n+1)
q=deque()
answer=[]
for i in range(m):
    tmp=list(map(int,input().split()))
    for j in range(1,tmp[0]):
        g[tmp[j]].append(tmp[j+1])
        in_degree[tmp[j+1]]+=1

for i in range(1,n+1):
    if in_degree[i]==0:
        q.append(i)

while q:
    t=q.popleft()
    answer.append(t)
    for i in g[t]:
        in_degree[i]-=1
        if in_degree[i]==0:
            q.append(i)

if sum(in_degree)==0:
    print(*answer)
else:
    print(0)