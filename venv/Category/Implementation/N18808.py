import sys;input=sys.stdin.readline
N,M,K=map(int,input().split())
g=[[0]*M for i in range(N)]
sticker=[]
for i in range(K):
    i,j=map(int,input().split())
    t=[list(map(int,input().split())) for _ in range(i)]
    sticker.append([i,j,t])

def pg(graph):
    print()
    for i in graph:
        print(*i)

def countStickedArea(graph):
    cnt=0
    for i in range(N):
        for j in range(M):
            if graph[i][j]:
                cnt+=1
    return cnt

def rotate90(metrix):
    n=len(metrix)
    m=len(metrix[0])
    copied=[[0]*n for i in range(m)]
    for i in range(n):
        for j in range(m):
            copied[j][n-1-i]=metrix[i][j]
    return [m,n,copied]

def stickSticker(idx, graph, x,y):
    r,c,stk=sticker[idx]
    for i in range(r):
        for j in range(c):
            if stk[i][j]:
                graph[x+i][y+j]=1
    return graph

def canStick(idx, graph):
    r,c,tmp_sticker=sticker[idx]
    for i in range(N-r+1):
        for j in range(M-c+1):
            possible=True
            for p in range(r):
                if(not possible): break
                for q in range(c):
                    if graph[i+p][j+q]+tmp_sticker[p][q]>=2:
                        possible=False
            if(possible):
                return [i,j]
    return [-1,-1]

ans=0
def dfs(idx, graph):
    global ans
    if idx==K:
        ans=max(ans,countStickedArea(graph))
        return 

    for i in range(4):
        x,y=canStick(idx,graph)
        if(x==-1):
            sticker[idx]=rotate90(sticker[idx][2])
            continue
        graph=stickSticker(idx,graph,x,y)
        break
    dfs(idx+1, graph)

dfs(0,g)
print(ans)