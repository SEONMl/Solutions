# 220507 | 이해 ㄴ
import heapq,sys
INF=float('inf')
V,E=map(int, sys.stdin.readline().split())
K=int(input())
g=[[] for i in range(V+1)]
ans=[INF]*(V+1)
q=[]
for i in range(E):
    u,v,w=map(int, sys.stdin.readline().split()) # start, end, cost
    g[u].append([v,w])

def dijkstra(start):
    ans[start]=0
    heapq.heappush(q,[0,start])
    while q:
        cur_w,cur_node=heapq.heappop(q)

        if ans[cur_node] <cur_w:
            continue
        for next_node,weight in g[cur_node]:
            next_w=cur_w+weight

            if next_w<ans[next_node]:
                ans[next_node]=next_w
                heapq.heappush(q,[next_w,next_node])
dijkstra(K)
for i in ans[1:]:
    print(i if i!=INF else "INF")