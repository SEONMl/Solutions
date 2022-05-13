# 220513 | i*2 OR str(i)+"1"
import sys
from collections import deque
a,b=map(int,input().split())
q=deque([(a,1)])
res=-1
while q:
    tmp,cnt=q.popleft()
    if tmp==b:
        res=cnt
        break
    if tmp*2<=b:
        q.append((tmp*2,cnt+1))
    if int(str(tmp)+"1")<=b:
        q.append((int(str(tmp)+"1"),cnt+1))
print(res)