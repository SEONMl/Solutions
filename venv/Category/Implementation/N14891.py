from collections import deque
arr=[deque(map(int,input())) for i in range(4)]
# N:0, S:1  | arr[i][0]:12시방향 1 2 4 8점
# arr[i-1][6]-arr[i][2]-arr[i+1][6]


n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    a-=1

    tmp6=arr[a][6]
    tmp2=arr[a][2]
    l,r,t=a-1,a+1,b
    arr[a].rotate(b)

    while l>=0: # 조건 잘 보자 ^.^
        if arr[l][2]!=tmp6:
            t*=-1
            tmp6=arr[l][6]
            arr[l].rotate(t)
            l-=1
        else:
            break
    t=b
    while r<4:
        if arr[r][6]!=tmp2:
            t*=-1
            tmp2=arr[r][2]
            arr[r].rotate(t)
            r+=1
        else:
            break


res=0
for i in range(4):
    res+=arr[i][0]*(2**(i))
print(res)
