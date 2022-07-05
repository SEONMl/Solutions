import sys, heapq

input=sys.stdin.readline
T=int(input())
INF=float('inf')

def dijkstra(start):
    visit=[INF]*(n+1)
    visit[start]=0
    heap=[]
    heapq.heappush(heap,(0,start))
    while heap:
        weight, cur = heapq.heappop(heap)
        if visit[cur]<weight:
            continue
        for w,c in g[cur]:
            nw=w+weight
            if nw<visit[c]:
                visit[c]=nw
                heapq.heappush(heap,(nw,c))
    return visit


for _ in range(T):
    # 출발지 s -> x까지 최단거리, g와 h 사이 도로 필수로 지나감
    n,m,t=map(int,input().split()) # 교차로, 도로, 목적지 후보 개수
    s,g0,h0=map(int,input().split()) # 출발지
    g=[[] for i in range(n+1)]
    x=[]
    for i in range(m):
        a,b,d=map(int,input().split()) # a,b 사이 양방향 도로 d | 도로는 하나
        if (a==g0 and b==h0) or (a==h0 and b==g0):
            g[a].append([d-0.1, b])
            g[b].append([d-0.1, a])
        else:
            g[a].append([d,b])
            g[b].append([d,a])
    for i in range(t):
        x.append(int(input())) # 목적지 후보 t!=s

    arr=dijkstra(s)
    res=[]
    for target in x:
        if arr[target] != INF and type(arr[target])==float:
            res.append(target)
    res.sort()
    print(*res)

