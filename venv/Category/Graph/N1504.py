import sys,heapq
input=sys.stdin.readline
INF=sys.maxsize
N,E=map(int,input().split())
g=[[]*(N+1) for i in range(N+1)]
for _ in range(E):
    a,b,c=map(int,input().split())
    g[a].append((c,b))
    g[b].append((c,a))
w,v=map(int,input().split())

def dijkstra(start):
    visit=[INF]*(N+1)
    visit[start]=0
    heap=[]
    heapq.heappush(heap,(0,start))
    while heap:
        cur_w,cur=heapq.heappop(heap)
        if visit[cur]<cur_w:
            continue
        for weight,node in g[cur]:
            nw=weight+cur_w
            if nw<visit[node]:
                visit[node]=nw
                heapq.heappush(heap,(nw,node))
    return visit

arr=dijkstra(1)
v1=dijkstra(v)
v2=dijkstra(w)
ans=min(arr[v]+v1[w]+v2[N],arr[w]+v2[v]+v1[N])
print(ans if ans<INF else -1)