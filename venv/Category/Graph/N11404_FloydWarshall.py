# 플로이드-와샬 O(n^3)
import sys
input=sys.stdin.readline
n=int(input())
m=int(input())
INF=sys.maxsize
dist=[[INF]*(n+1) for i in range(n+1)]
for i in range(m):
    a,b,c=map(int,input().split())
    dist[a][b]=min(dist[a][b],c)
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i==j:
                continue
            dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j])

for i in range(1,n+1):
    for j in range(1,n+1):
        if dist[i][j]==INF:
            print(0,end=" ")
        else:
            print(dist[i][j],end=" ")
    print()