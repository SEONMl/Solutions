from collections import deque
R,C=map(int,input().split())
g=[' '.join(input()).split() for i in range(R)]
N=int(input())
h=list(map(int,input().split()))
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def bfs(a,b):
    global isBottom
    q=deque()
    lst=[-1]*C
    coor=[]
    q.append((a,b))
    visit[a][b]=1
    while q:
        x,y=q.popleft()
        lst[y]=max(x,lst[y])
        coor.append((x,y))
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<R and 0<=ny<C and not visit[nx][ny] and g[nx][ny]=="x":
                visit[nx][ny]=1
                q.append((nx,ny))
                if nx+1>=R:
                    isBottom=True
    if isBottom:
        return
    else:
        gravity(lst,coor)

def gravity(lst,coor): # 2 3 -1 -1 -1 -1 | 2 0 / 2 1 / 3 1
    mmin=R
    for i in range(C):
        if lst[i]!=-1:
            t=0
            for j in range(lst[i]+1,R):
                if g[j][i]==".":
                    t+=1
                else:
                    break
            mmin=min(t,mmin)
    for j, k in coor:
        g[j][k] = "."
    for j,k in coor:
        visit[j+mmin][k]=1
        g[j+mmin][k]="x"

def printing(arr):
    for i in range(R):
        print(''.join(arr[i]))

for i in range(N):
    visit=[[0]*C for _ in range(R)]
    didShoot=False
    tmp=[]
    # 창 던지기
    if not i%2: # 홀수 번
        for j in range(C):
            if g[R-h[i]][j]=="x":
                didShoot=True
                g[R-h[i]][j]="."
                break
    else: # 짝수 번
        for j in range(C-1,-1,-1):
            if g[R-h[i]][j]=="x":
                didShoot=True
                g[R-h[i]][j]="."
                break

    # 중력
    if not didShoot:
        continue

    for j in range(R):
        for k in range(C):
            if g[j][k]=="x" and not visit[j][k]:
                isBottom = False
                bfs(j,k)

printing(g)