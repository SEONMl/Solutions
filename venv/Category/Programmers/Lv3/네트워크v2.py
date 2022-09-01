from collections import deque
def solution(n,computers):
    cnt=0
    g=[[]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i!=j and computers[i][j]==1:
                g[i].append(j)
    visit=[0]*n
    def bfs(s,visit):
        q=deque()
        q.append(s)
        visit[s]=1
        while q:
            t=q.popleft()
            for i in g[t]:
                if not visit[i]:
                    q.append(i)
                    visit[i]=1
    for i in range(n):
        if not visit[i]:
            bfs(i,visit)
            cnt+=1
    return cnt
print(solution(3,[[1, 1, 0], [1, 1, 0], [0, 0, 1]])) # 2
print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]])) # 1