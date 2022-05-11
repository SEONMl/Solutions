import sys,heapq
input=sys.stdin.readline
INF=int(1e9)
n=int(input())
m=int(input())

distance=[INF]*(n+1)
g=[[] for i in range(n+1)]
for i in range(m):
    u,v,c=map(int,input().split()) # 노드 u에서 노드 v로 갈 때 드는 비용 c
    g[u].append([v,c])
start,end=map(int,input().split())

def dijkstra(start):
    q=[]
    heapq.heappush(q,[0,start])
    while q:
        curCost,curNode=heapq.heappop(q)
        if distance[curNode]<curCost:
            continue
        for i in g[curNode]:
            nextCost=curCost+i[1]
            if distance[i[0]]>nextCost:
                distance[i[0]]=nextCost
                heapq.heappush(q,(nextCost,i[0]))
dijkstra(start)
print(distance[end])