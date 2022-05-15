# 220507 | 이해 ㄴ
# 최단 거리 배열을 무한대로, 방문여부 배열은 False로 초기화
# 출발 노드는 방문했다고 체크하고 heap에 넣는다
# 아직 방문하지 않은 노드들 중 최단 거리 테이블 값이 가장 작은 노드를 선택
# 저장된 최단거리 값과 현재 노드에 가중치를 더한 값 중 작은 값으로 update
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