from collections import deque
import sys
input=sys.stdin.readline

n=int(input())
m=int(input())
g=[[] for i in range(n+1)]
back_g=[[] for i in range(n+1)]
in_degree=[0]*(n+1)
visit=[0]*(n+1)

for i in range(m):
    a,b,c=map(int,input().split())
    g[a].append((b,c))
    back_g[b].append((a,c))
    in_degree[b]+=1
start,end=map(int,input().split())

q=deque()
q.append(start)
topology=[0]*(n+1)

while q:
    t=q.popleft()
    for i,j in g[t]:
        in_degree[i]-=1
        topology[i]=max(topology[i],topology[t]+j)
        if in_degree[i]==0:
            q.append(i)
cnt=0
q.append(end)
while q:
    t=q.popleft()
    for i,j in back_g[t]:
        if topology[t]-topology[i]==j:
            cnt+=1
            if visit[i]==0:
                q.append(i)
                visit[i]=1
print(topology[end])
print(cnt)

'''
임계경로는 전체 중에서 여러 경로가 동시에 이루어질 때, 가장 오래 걸리는 경로를 의미한다. 
'''