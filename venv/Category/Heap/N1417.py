import sys,heapq as h; input=sys.stdin.readline
N=int(input())
heap=[]
dasom=int(input())
cnt=0
if N!=1:
    for i in range(N-1):
        n=int(input())
        h.heappush(heap, -n)
    while -heap[0]>=dasom:
        n=h.heappop(heap)
        h.heappush(heap, n+1)
        cnt+=1
        dasom+=1
print(cnt)