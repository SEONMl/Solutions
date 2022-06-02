import sys
from collections import deque
input=sys.stdin.readline
dx=[1,-1,0,0,1,1,-1,-1]
dy=[0,0,1,-1,1,-1,1,-1]
def bfs(arr,y,x):
    q= deque()
    q.append((y,x))
    while q:
        y,x = q.popleft()
        for i in range(8):
            nx = x+dx[i]
            ny = y+dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if arr[ny][nx]==0:
                continue

            if arr[ny][nx]==1:
                arr[ny][nx]=0
                q.append((ny,nx))

while 1:
    n,m=map(int,input().split()) # m * n
    if n==0 and m==0:
        break

    arr=[]
    for i in range(m):
        arr.append(list(map(int,input().split())))

    cnt=0
    for i in range(m):
        for j in range(n):
            if arr[i][j] == 1:
                cnt += 1
                bfs(arr,i, j)
    print(cnt)

