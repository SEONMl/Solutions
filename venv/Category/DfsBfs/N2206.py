import sys
from collections import deque
Y,X=map(int,input().split())
broken=0
g=[]
for i in range(1,Y+1):
    g.append(list(map(int,' '.join(sys.stdin.readline()).split())))
q=deque()
q.append((1,1))
while 1:
    t=q.popleft()
    if t==(X,Y):
        break
