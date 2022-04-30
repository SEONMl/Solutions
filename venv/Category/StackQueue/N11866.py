# 220418 정답 | 복습여부
from collections import deque
n, k = map(int, input().split())
killed=[]

q=deque(i for i in range(n,0,-1))
while q:
    for _ in range(k-1):
        tmp=q.pop()
        q.appendleft(tmp)
    killed.append(str(q.pop()))

print("<",end="")
print(", ".join(killed), end="")
print(">")