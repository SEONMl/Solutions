from collections import deque

n=int(input()) # Node
e=int(input()) # Edge
graph=[[0] for i in range(n+1)] # 그래프
visited=[0] * (n+1) # 노드 방문 여부

for i in range(e):
    a,b =map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

cnt=0
q=deque()
for i in range(1,n+1):
    for j in range(i,n+1):
        if graph[i][j] == 1 :
            cnt+=1

def dfs(num):
    visited[num]=1
    for i in range(1, n+1):
        if visited[num]==0:
            dfs(i)


print(cnt)