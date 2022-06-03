'''
from collections import deque
n,m=map(int,input().split())
g=[] # .:빈칸 #:벽 O:구멍 R:빨간공 B:파란공
dx=[1,-1,0,0]
dy=[0,0,1,-1]
visit=[[[[False]*m for _ in range(n)] for _ in range(m)] for _ in range(n)]
def bfs(arr,x1,y1,x2,y2):
    q=deque()
    q.append([x1,y1,x2,y2,1]) #x,y,x,y,회전 수
    visit[x1][y1][x2][y2]=True

    while q:
        rx,ry,bx,by,r=q.popleft()

        if r>10:
            return -1

        for i in range(4):
            nrx,nry,rcnt=move(rx,ry,dx[i],dy[i])
            nbx,nby,bcnt=move(bx,by,dx[i],dy[i])
            if arr[nbx][nby]!="O":
                if arr[nrx][nry]=="O":
                    return r

                if nrx==nbx and nry==nby:
                    if rcnt>bcnt:
                        nrx-=dx[i]
                        nry-=dy[i]
                    else:
                        nbx-=dx[i]
                        nby-=dx[i]

                if not visit[nrx][nry][nbx][nby]:
                    visit[nrx][nry][nbx][nby]=True
                    q.append([nrx,nry,nbx,nby,r+1])
    return -1

def move(x,y,dx,dy):
    cnt=0
    try:
        while g[x+dx][y+dy]!="#" and g[x][y]!="O":
            x+=dx
            y+=dy
            cnt+=1
        return [x,y,cnt]
    except:
        print(g[x][y])
        print(x)
        print(y)
        print(y+dy)


for i in range(n):
    g.append(list(map(str,' '.join(input()).split())))
    for j in range(m):
        if g[i][j]=="B":
            bx,by=i,j
        if g[i][j]=="R":
            rx,ry=i,j

a=bfs(g,rx,ry,bx,by)
if a>10 or a==-1:
    print(0)
else:
    print(a)
# 10 초과일 경우 -1
'''

from collections import deque
n, m = map(int, input().split())
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
visit = [[[[False] * m for i in range(n)] for i in range(m)] for i in range(n)]
s = []
def move(i, j, dx, dy):
    c = 0
    while s[i + dx][j + dy] != "#" and s[i][j] != "O":
        i += dx
        j += dy
        c += 1
    return i, j, c
def bfs():
    while q:
        ri, rj, bi, bj, d = q.popleft()
        if d > 10:
            break
        for i in range(4):
            nri, nrj, rc = move(ri, rj, dx[i], dy[i])
            nbi, nbj, bc = move(bi, bj, dx[i], dy[i])
            if s[nbi][nbj] != "O":
                if s[nri][nrj] == "O":
                    print(d)
                    return
                if nri == nbi and nrj == nbj:
                    if rc > bc:
                        nri -= dx[i]
                        nrj -= dy[i]
                    else:
                        nbi -= dx[i]
                        nbj -= dy[i]
                if not visit[nri][nrj][nbi][nbj]:
                    visit[nri][nrj][nbi][nbj] = True
                    q.append([nri, nrj, nbi, nbj, d + 1])
    print(-1)
for i in range(n):
    a = list(input())
    s.append(a)
    for j in range(m):
        if a[j] == "R":
            ri, rj = i, j
        if a[j] == "B":
            bi, bj = i, j
q = deque()
q.append([ri, rj, bi, bj, 1])
visit[ri][rj][bi][bj] = True
bfs()