import sys
from collections import deque
input=sys.stdin.readline
n,m=map(int,input().split())
g=[[] for i in range(n+1)]
in_degree=[0]*(n+1)
q=deque()
answer=[]
for _ in range(m):
    a,b=map(int,input().split())
    g[a].append(b)
    in_degree[b]+=1

for i in range(1,n+1):
    if in_degree[i]==0:
        q.append(i)

while q:
    tmp=q.popleft()
    answer.append(tmp)
    for i in g[tmp]:
        in_degree[i]-=1
        if in_degree[i]==0:
            q.append(i)

print(*answer)
'''
위상정렬

진입차수가 0인 정점을 큐에 삽입
큐에서 원소를 꺼내 해당 원소와 연결된 간선을 모두 제거
제거한 후에 진입차수가 0인 정점을 큐에 삽입
'''