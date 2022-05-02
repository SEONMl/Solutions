import sys
n=int(input())
m=[list(map(int,sys.stdin.readline().split())) for i in range(n)]
cnt=[0,0,0]
def dq(arr,x,y,k):
    cur=arr[y][x]
    dx=k//3
    dy=k//3
    for i in range(y,y+k):
        for j in range(x,x+k):
            if arr[i][j]!=cur:
                dq(arr,x,y,k//3)
                dq(arr,x+dx,y,k//3)
                dq(arr,x+dx*2,y,k//3)
                dq(arr,x,y+dy,k//3)
                dq(arr,x,y+dy*2,k//3)
                dq(arr,x+dx*2,y+dy*2,k//3)
                dq(arr,x+dx,y+dy,k//3)
                dq(arr,x+dx*2,y+dy,k//3)
                dq(arr,x+dx,y+dy*2,k//3)
                return
    cnt[cur+1]+=1
dq(m,0,0,n)
for i in cnt:
    print(i)
