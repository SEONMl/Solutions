from collections import deque
def solution(n, edge):
    g=[[] for i in range(n+1)]
    cnt=0
    for i,j in edge:
        g[i].append(j)
        g[j].append(i)
    visit=[0]*(n+1)
    bfs(g,visit,1)
    for i in visit:
        if i==max(visit):
            cnt+=1
    return cnt
def bfs(arr,visit,start):
    node = 1
    q=deque()
    visit[start]=1
    q.append([start,node])
    while q:
        t,cnt=q.popleft()
        for i in arr[t]:
            if visit[i]==0:
                q.append([i,cnt+1])
                visit[i]=cnt+1

n=6
v=[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]
print(solution(n,v))