import heapq as h,sys;input=sys.stdin.readline
N=int(input())
arr=[list(map(int,input().split()))[1:] for i in range(N)]
arr.sort()
q=[]
for i in range(N):
    if q and q[0]<=arr[i][0]:
        h.heappop(q)
    h.heappush(q,arr[i][1])
print(len(q))