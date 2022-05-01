from collections import deque
c=int(input())
dx=[2,2,-2,-2,1,1,-1,-1]
dy=[1,-1,1,-1,2,-2,2,-2]
def bfs(arr,start,end):
    q=deque()
    q.append(start)
    while q:
        t=q.popleft()
        if t==end:
            print(arr[t[1]][t[0]])
            break
        for j in range(8):
            nx=t[0]+dx[j]
            ny=t[1]+dy[j]
            if 0<=nx<N and 0<=ny<N and not arr[ny][nx]:
                arr[ny][nx]=arr[t[1]][t[0]]+1
                q.append((nx,ny))
for i in range(c):
    N=int(input())
    cur=tuple(map(int, input().split()))
    end=tuple(map(int,input().split()))
    g=[[0]*N for i in range(N)]
    bfs(g,cur,end)
