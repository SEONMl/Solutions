from collections import deque
F,S,G,U,D=map(int,input().split())
# 총 F층, 강호 현재 S층, 목적지 G층, U개의 층 이동, D개의 층 이동
errmsg="use the stairs"
dt=[U,-D]
def bfs(s):
    q=deque()
    q.append((s,0))
    visit=[False]*(F+1)
    visit[s]=True
    while q:
        t,cnt=q.popleft()
        if t==G:
            return cnt
        for i in range(2):
            nt=t+dt[i]
            if 1<=nt<=F and not visit[nt]:
                visit[nt]=True
                q.append((nt,cnt+1))
    return None

cnt=bfs(S)
if cnt is None:
    print(errmsg)
else:
    print(cnt)