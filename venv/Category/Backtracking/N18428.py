import sys;input=sys.stdin.readline
N=int(input())
g=[list(map(str,input().rstrip().split())) for i in range(N)]
dx=[0,0,1,-1]
dy=[1,-1,0,0]
def bt(arr, depth):
    if depth==3:
        if check(arr):
            print("YES")
            exit(0)
    else:
        for i in range(N):
            for j in range(N):
                if arr[i][j]=="X":
                    arr[i][j]="O"
                    bt(arr,depth+1)
                    arr[i][j]="X"
def check(arr):
    cntT=0
    cnt=0
    for i in range(N):
        for j in range(N):
            if arr[i][j]=="T":
                cntT+=1
                if dfs(arr,i,j):
                    cnt+=1
    if cnt==cntT:
        return True
    return False
def dfs(arr,i,j):
    for t in range(4):
        ni,nj=i+dx[t],j+dy[t]
        while 0<=ni<N and 0<=nj<N:
            if arr[ni][nj]=="S":
                return False
            if arr[ni][nj]=="O":
                break
            ni+=dx[t]
            nj+=dy[t]
    return True
bt(g,0)
print("NO")