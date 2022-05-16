# 와이 시간초과
from collections import deque
n,k=map(int,input().split())
mMax=100000

def bfs(start):
    visit=[0]*(mMax+1)
    q=deque([start])
    while q:
        t=q.popleft()
        if t==k:
            print(visit[t])
            exit(0)
        if t*2<=mMax and not visit[t*2]:
            q.appendleft(t*2)
            visit[t*2]=visit[t]
        if 0<=t-1 and not visit[t-1]:
            q.append(t-1)
            visit[t-1]=visit[t]+1
        if t+1<=mMax and not visit[t+1]:
            q.append(t+1)
            visit[t+1]=visit[t]+1
bfs(n)