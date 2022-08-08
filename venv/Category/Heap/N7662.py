import sys,heapq
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    k=int(input())
    nq,xq=[],[]
    visit=[0]*k
    for i in range(k):
        opr,n=input().split()
        n=int(n)
        if opr=="I":
            heapq.heappush(nq,(n,i))
            heapq.heappush(xq,(-n,i))
            visit[i]=1
        else:
            if n==1:
                while xq and not visit[xq[0][1]]:
                    heapq.heappop(xq)
                if xq:
                    visit[xq[0][1]]=0
                    heapq.heappop(xq)
            else:
                while nq and not visit[nq[0][1]]:
                    heapq.heappop(nq)
                if nq:
                    visit[nq[0][1]]=0
                    heapq.heappop(nq)
    while xq and not visit[xq[0][1]]:
        heapq.heappop(xq)
    while nq and not visit[nq[0][1]]:
        heapq.heappop(nq)

    if nq and xq:
        print(-xq[0][0],nq[0][0])
    else:
        print("EMPTY")