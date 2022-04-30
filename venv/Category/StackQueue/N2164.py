# 220418 정답
from collections import deque
n=int(input())
# n장의 카드 | 맨 위 카드는 버림, 그 다음 맨 위 카드를 맨 아래로 옮긴다 <-이게 한 사이클

q=deque(i for i in range(n,0,-1))

while len(q)>1 :
    q.pop()
    if len(q)==1:
        break
    tmp=q.pop()
    q.appendleft(tmp)

print(q[0])

