import sys;input=sys.stdin.readline
# 부모 테이블을 항상 가지고 있어야 한다
# 서로소 집합
# 방향성 없는 무향 그래프에서만
sys.setrecursionlimit(10**8)
N,M=map(int,input().split())
parent=[]
for i in range(N+1):
    parent.append(i)

def find(x):
    if parent[x]!=x:
        parent[x]=find(parent[x])
    return parent[x]

def union(a,b):
    a=find(a)
    b=find(b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b

for _ in range(M):
    cmd,a,b=map(int,input().split())
    if cmd==0:
        union(a,b)
    else:
        a=find(a)
        b=find(b)
        if(a!=b):
            print("NO")
        else:
            print("YES")