# 오래걸림 -> pop(0) 쓸 바에 deque import 해서 사용해라
from collections import deque
N=int(input())
L=deque(sorted(list(map(int,input().split()))))
if N==2:
    print(1)
    exit(0)
cnt=0
tmp=0
while len(L)>1:
    if tmp==0:
        tmp=L.popleft()
    a,b=L.pop(),L.pop()
    L.append(a+b+1)
    cnt+=1
    tmp-=1
if tmp>0:
    cnt+=1
print(cnt)