import sys;input=sys.stdin.readline
N,M=map(int,input().split())
g=[list(map(int,input().split())) for i in range(N)]
dx=[0,0,1,-1] # 우 좌 하 상
dy=[1,-1,0,0]

lv1=[0,1,2,3]
lv2=[[0,1],[2,3]]
lv3=[[0,2],[0,3],[1,2],[1,3]]
lv4=[[0,1,2],[0,1,3],[0,2,3],[1,2,3]]

def countEmptyRoom(graph):
    cnt=0
    for i in range(N):
        for j in range(M):
            if graph[i][j]==0:
                cnt+=1
    return cnt
def directOneDirection(graph,x,y, dir):
    copied=[[0]*M for i in range(N)]
    for i in range(N):
        for j in range(M):
            copied[i][j]=graph[i][j]

    while(0<=x<N and 0<=y<M and g[x][y]!=6):
        if copied[x][y]==0:
            copied[x][y]=7
        nx, ny=x+dx[dir], y+dy[dir]
        x,y=nx,ny
    return copied

def directByLevel(graph,x,y,lvl,j):
    if lvl==1:
        graph=directOneDirection(graph,x,y,lv1[j])
    elif lvl==2:
        for i in range(2):
            graph=directOneDirection(graph,x,y,lv2[j][i])
    elif lvl==3:
        for i in range(2):
            graph=directOneDirection(graph,x,y,lv3[j][i])
    elif lvl==4:
        for i in range(3):
            graph=directOneDirection(graph,x,y,lv4[j][i])
    return graph
    
cctv=[]
for i in range(N):
    for j in range(M):
        if 1<=g[i][j]<=4:
            cctv.append([i,j,g[i][j]])
        if g[i][j]==5:
            for k in range(4):
                g=directOneDirection(g,i,j,k)
L=len(cctv)
answer=N*M
def dfs(graph, idx):
    global answer
    if idx==L:
        answer=min(answer,countEmptyRoom(graph))
        return
    
    cur=cctv[idx]
    if cur[2]==1:
        for i in range(4):
            dfs(directByLevel(graph, cur[0],cur[1], 1, i),idx+1)
    elif cur[2]==2:
        for i in range(2):
            dfs(directByLevel(graph,cur[0],cur[1], 2, i),idx+1)
    elif cur[2]==3:
        for i in range(4):
            dfs(directByLevel(graph, cur[0],cur[1], 3, i),idx+1)
    else:
        for i in range(4):
            dfs(directByLevel(graph, cur[0],cur[1], 4, i),idx+1)

dfs(g,0)
print(answer)