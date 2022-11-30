import sys;input=sys.stdin.readline
sys.setrecursionlimit(10**8)
N=int(input())
M=int(input())
parent=[0]*(N+1)
for i in range(1,N+1):
    parent[i]=i
def find(node):
    if node==parent[node]: return node
    parent[node]=find(parent[node])
    return parent[node]

def union(n1,n2):
    n1=find(n1)
    n2=find(n2)
    if n1==n2: return
    if n1<n2:
        parent[n2]=n1
    else:
        parent[n1]=n2
for i in range(1,N+1):
    g=list(map(int,input().split()))
    for j in range(1,N+1):
        if g[j-1]==1:
            union(i,j)
plan=list(map(int,input().split()))
result=set([find(i) for i in plan])

print("YES" if len(result)==1 else "NO")