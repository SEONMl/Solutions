import sys,heapq
input=sys.stdin.readline
N,M,R=map(int,input().split())
items=list(map(int,input().split()))
INF=sys.maxsize
g=[[] for i in range(N+1)]
for i in range(R):
    a,b,c=map(int,input().split())
    g[a].append((c,b))
    g[b].append((c,a))
ans=0
def dijkstra(s):
    q,res=[],0
    heapq.heappush(q,[0,s])
    distance=[INF]*(N+1)
    distance[s]=0
    while q:
        cur_w,cur_n=heapq.heappop(q)
        if distance[cur_n]<cur_w:
            continue
        for w,n in g[cur_n]:
            next_w=w+cur_w
            if distance[n]>next_w:
                heapq.heappush(q,(next_w,n))
                distance[n]=next_w
    for _i in range(1,N+1):
        if distance[_i]<=M:
            res+=items[_i-1]
    return res
for i in range(1,N+1):
    ans=max(dijkstra(i),ans)
print(ans)