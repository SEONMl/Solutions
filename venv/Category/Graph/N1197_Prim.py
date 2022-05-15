# 최소신장트리 - 전체 요소들을 연결
# 임이의 정점 선택
# 해당 정점에서 갈 수 있는 간선을 minheap에 넣는다
# 최솟값을 뽑아 해당 정점을 방문 안 했다면 선택
# 간선이 많으면 Prim | 시간 908ms
import sys, heapq
input=sys.stdin.readline
V,E=map(int,input().split())
visit=[0]*(V+1)
eList=[[] for _ in range(V+1)]
heap=[[0,1]]
for _ in range(E):
    s,e,w=map(int,input().split())
    eList[s].append([w,e])
    eList[e].append([w,s])

res=0
cnt=0
while heap:
    if cnt==V:
        break
    weight,start=heapq.heappop(heap)
    if not visit[start]:
        visit[start]=1
        res+=weight
        cnt+=1
        for i in eList[start]:
            heapq.heappush(heap,i)
print(res)