from collections import deque

n, m, v = map(int, input().split())
matrix = [[0] * (n + 1) for i in range(n + 1)];
isVisited = [0] * (n + 1)

# 그래프 행렬 정의
for i in range(m):
    a, b = map(int, input().split())
    matrix[a][b] = matrix[b][a] = 1


def dfs(v):
    isVisited[v] = 1
    print(v, end=" ")
    for i in range(n + 1):
        if (isVisited[i] == 0 & matrix[v][i] == 1):
            dfs(i)


def bfs(v):
    queue = deque()
    queue.append(v)
    print(v, end=" ")
    isVisited[v] = 1

    for i in range(n + 1):
        while queue:
            v = queue.popleft()
            print(v, end=" ")
            if (matrix[v][i] == 1 & isVisited[i] == 0):
                queue.append(i)
                isVisited[i] = True


dfs(v)
isVisited[v] = False
print()
bfs(v)
