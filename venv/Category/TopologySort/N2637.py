import sys;input=sys.stdin.readline
from collections import deque
N=int(input())
M=int(input())
next=[[] for i in range(N + 1)]
need=[[] for i in range(N + 1)]
dp=[0]*(N+1)
indegree=[0]*(N+1)
for i in range(M):
    x,y,k=map(int,input().split())
    next[y].append(x)
    need[x].append((y, k))
    indegree[x]+=1

q=deque()
for i in range(1,N+1):
    if indegree[i]==0:
        q.append(i)

topology=[]
while q:
    tmp=q.popleft()
    topology.append(tmp)

    for i in next[tmp]:
        indegree[i]-=1
        if indegree[i]==0:
            q.append(i)

dp[topology[N-1]]=1
for i in range(N-1,-1,-1):
    node=topology[i]
    for tar,cnt in need[node]:
        dp[tar]+=cnt*dp[node]
for i in range(1,N+1):
    if len(need[i])==0:
        print(i,dp[i])