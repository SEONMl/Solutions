import sys
input=sys.stdin.readline
R,C,T=map(int,input().split()) # 행,열,초
g=[list(map(int,input().split())) for i in range(R)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
for i in range(2,R):
    if g[i][0]==-1:
        pos_x=i
        break
def expansion():
    global g
    tmp=[]
    for i in range(R):
        for j in range(C):
            if g[i][j]>=5:
                tmp.append([i,j,g[i][j]//5])

    for i,j,v in tmp:
        for k in range(4):
            nx=i+dx[k]
            ny=j+dy[k]
            if 0<=nx<R and 0<=ny<C and g[nx][ny]!=-1:
                g[nx][ny]+=v
                g[i][j]-=v

def activation():
    global g, pos_x
    for i in range(pos_x,0,-1):
        g[i][0]=g[i-1][0]
    for i in range(0,C-1):
        g[0][i]=g[0][i+1]
    for i in range(0,pos_x):
        g[i][C-1]=g[i+1][C-1]
    for i in range(C-1,1,-1):
        g[pos_x][i]=g[pos_x][i-1]

    tmp_x=pos_x+1
    for i in range(tmp_x,R-1):
        g[i][0]=g[i+1][0]
    for i in range(C-1):
        g[R-1][i]=g[R-1][i+1]
    for i in range(R-1,tmp_x,-1):
        g[i][C-1]=g[i-1][C-1]
    for i in range(C-1,1,-1):
        g[tmp_x][i]=g[tmp_x][i-1]

    g[pos_x][1]=g[tmp_x][1]=0
    g[pos_x][0]=g[tmp_x][0]=-1

for _ in range(T):
    # 먼지가 확산한다
    expansion()
    # 공기청정기가 작동한다
    activation()

res=0
for i in range(R):
    res+=sum(g[i])
print(res+2)