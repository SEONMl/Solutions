# 220418
from collections import deque

N = int(input())
# <- [ queue ] <-
for i in range(N):
    n,m=map(int,input().split()) # n:문서개수, m:인덱스
    arr=list(map(int,input().split())) # 중요도
    a=deque()
    for i in range(n):
        a.append([arr[i],i])
    while 1:
        mmax=max(a)[0]
        if a[0][0]==mmax:
            i,j=a.popleft()
            if j==m:
                break
        else:
            a.append(a.popleft())
    print(n-len(a))