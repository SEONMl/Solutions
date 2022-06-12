from collections import deque
g=[list(map(str,' '.join(input()).split())) for i in range(12)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
# R G B P Y
def bfs(a,b):
    global visit
    q=deque()
    coor=[]
    coor.append([a,b])
    q.append([a,b,1])
    visit[a][b]=1
    while q:
        x,y,c=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<12 and 0<=ny<6 and visit[nx][ny]==0 and g[nx][ny]==g[a][b]:
                visit[nx][ny]=1
                if [nx,ny] not in coor:
                    coor.append([nx,ny])
                q.append((nx,ny,c+1))
    return coor
pop_cnt=0
while 1:
    visit=[[0]*6 for i in range(12)]
    dic={"R":0,"G":1,"B":2,"P":3,"Y":4}
    lst=[]
    didPoped=False
    for i in range(12):
        for j in range(6):
            if visit[i][j]==0 and g[i][j]!=".":
                lst.append(bfs(i,j))

    for k in range(len(lst)):
        if len(lst[k])>=4:
            for i,j in lst[k]:
                g[i][j]="."
                didPoped=True
    for i in range(6):
        t=0
        for j in range(11,0,-1):
            if g[j][i]!=".":
                break
            else:
                t+=1
        if t==11:
            continue

        for j in range(t):
            g[11-j][i]=g[11-j-t][i]
            g[11-j-t][i]="."

    if not didPoped:
        print(pop_cnt)
        exit(0)
    else:
        pop_cnt+=1