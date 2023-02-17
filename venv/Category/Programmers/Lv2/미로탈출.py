from collections import deque
dx=[0,0,1,-1]
dy=[1,-1,0,0]
INF=99999999
def bfs(g, cur, to):
    visit=[[INF]*M for i in range(N)]
    visit[cur[0]][cur[1]]=0
    q=deque()
    q.append([cur[0], cur[1],0])

    while q:
        x,y,t = q.popleft()
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            if(0<=nx<N and 0<=ny<M and g[nx][ny]!='X' and visit[nx][ny]>t+1 ):
                q.append([nx,ny,t+1])
                visit[nx][ny]=t+1
    
    return visit[to[0]][to[1]]

def solution(g):
    global N,M
    N=len(g)
    M=len(g[0])
    for i in range(N):
        for j in range(M):
            if(g[i][j]=='S') :
                start=(i,j)
            if(g[i][j]=='L'):
                lever=(i,j)
            if(g[i][j]=='E'):
                end=(i,j)

    sec1=bfs(g, start, lever)
    if(sec1==INF):
        return -1
    sec2=bfs(g, lever, end)
    if(sec2==INF):
        return -1
    return sec1+sec2
    
print(solution(["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]))
print(solution(["LXOOS","XOOOO","OOOOO","OOOOO","EOOOO"]))