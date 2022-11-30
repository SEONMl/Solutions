import sys;input=sys.stdin.readline
from collections import deque
N,M=map(int,input().split())
g=[list(map(int,input().split())) for i in range(M)]
parent=[]
for i in range(N+1):
    parent.append(i)
def find(x):
    if parent[x]!=x:
        return find(parent[x])
    return x
def union(a,b):
    a=find(a)
    b=find(b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b
g.sort(key=lambda a:a[2])
prev=0
ans=0
for a,b,cost in g:
    aRoot=find(a)
    bRoot=find(b)
    if aRoot==bRoot:
        continue
    union(a,b)
    ans+=cost
    prev=cost
print(ans-prev)