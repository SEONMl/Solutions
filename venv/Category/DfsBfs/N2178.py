# 미로(2차원배열) 최소경로 찾기

from collections import deque

n, m = map(int, input().split())

maze = [list(map(int, ' '.join(input()).split())) for i in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

q = deque([(0, 0)])

while q:
    x ,y = q.popleft()
    for i in range(4):

        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m :
            if (maze[nx][ny] == 1):
                maze[nx][ny] = maze[x][y] + 1
                q.append((nx, ny))

print(maze[n - 1][m - 1])
