from collections import deque
g=[list(map(str,' '.join(input()).split())) for i in range(12)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
dic = {"R": 0, "G": 1, "B": 2, "P": 3, "Y": 4}
pop_cnt=0
# R G B P Y
def bfs(a,b):
    global visit
    q=deque()
    coor=[]
    coor.append([a,b])
    q.append([a,b])
    visit[a][b]=1
    while q:
        x,y=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<12 and 0<=ny<6 and visit[nx][ny]==0 and g[nx][ny]==g[a][b]:
                visit[nx][ny]=1
                if [nx,ny] not in coor:
                    coor.append([nx,ny])
                q.append((nx,ny))
    if len(coor)>=4:
        for x,y in coor:
            g[x][y]="."
        return 1
    else:
        return 0

def gravity():
    global g
    for y in range(6):
        q=deque()
        for x in range(11,-1,-1):
            if g[x][y]!=".":
                q.append(g[x][y])
        for x in range(11,-1,-1):
            if q:
                g[x][y]=q.popleft()
            else:
                g[x][y]="."

while 1:
    visit=[[0]*6 for i in range(12)]
    isPoped=0
    for i in range(12):
        for j in range(6):
            if visit[i][j]==0 and g[i][j]!=".":
                isPoped+=bfs(i,j)

    if not isPoped:
        print(pop_cnt)
        exit(0)
    else:
        pop_cnt+=1
    gravity()