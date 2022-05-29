# 드릅다 I will be back soon...
from collections import deque
def solution(board):
    n=len(board)
    bfs(board)

    for i in range(n):
        print(*board[i])

    return board[n-1][n-1]

def bfs(arr): #[[]]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    n=len(arr)
    q=deque()
    q.append((0,0,0)) #x, y ,dir(0은 상하, 1은 좌우이동)
    while q:
        x,y,dir=q.popleft()

        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            cur_dir=i%2
            if 0<=nx<n and 0<=ny<n:
                if arr[nx][ny]==0 or (cur_dir==dir and arr[nx][ny]>=arr[x][y]+100) or (cur_dir!=dir and arr[nx][ny]>=arr[x][y]+600):
                    if (x,y)==(0,0) or dir==cur_dir:
                        arr[nx][ny]=arr[x][y]+100
                    else:
                        arr[nx][ny]=arr[x][y]+600

                    q.append((nx,ny,cur_dir))
    return
b1=[[0,0,0],[0,0,0],[0,0,0]] # 900
b2=[[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]] # 3800
b3=[[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]] # 2100
b4=[[0,0,0,0,0,0],[0,1,1,1,1,0],[0,0,1,0,0,0],[1,0,0,1,0,1],[0,1,0,0,0,1],[0,0,0,0,0,0]] # 3200
print(solution(b4))