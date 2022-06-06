g=[list(map(int,input().split())) for i in range(9)]
# 0-3-6
a=[]
for i in range(9):
    for j in range(9):
        if g[i][j]==0:
            a.append([i,j])

def row(i,a):
    global g
    for k in range(9):
        if a==g[i][k]:
            return False
    return True

def column(j,a):
    global g
    for k in range(9):
        if a==g[k][j]:
            return False
    return True

def rectangle(i,j,a):
    global g
    nx=i//3*3
    ny=j//3*3
    for i in range(3):
        for j in range(3):
            if g[nx+i][ny+j]==a:
                return False
    return True

def dfs(idx):
    global g
    if idx==len(a):
        for i in range(9):
            print(*g[i])
        return

    i=a[idx][0]
    j=a[idx][1]
    for k in range(1,10):
        if row(i,k) and column(j,k) and rectangle(i,j,k):
            g[i][j]=k
            dfs(idx+1)
            g[i][j]=0
dfs(0)