n=int(input())
a=[list(map(int, ' '.join(input()).split())) for i in range(n)]

total=0
dx=[1,-1,0,0]
dy=[0,0,1,-1]

def dfs(x, y):
    if x<0 or y<0 or x>=n or y>=n:
        return False

    if a[x][y]==1:
        global total
        total+=1
        a[x][y]=0
        for i in range(4):
            nx=x+dx[i]
            ny=y+dy[i]
            dfs(nx, ny)
        return True
    return False

r=[]
for i in range(n):
    for j in range(n):
        total = 0
        if dfs(i,j)==True:
            r.append(total)

r.sort()
print(len(r))
for i in r:
    print(i)