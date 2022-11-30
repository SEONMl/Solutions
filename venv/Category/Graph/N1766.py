import sys;input=sys.stdin.readline
import heapq as hq
N,M=map(int,input().split())
indegree=[0]*(N+1)
arr=[[] for i in range(N+1)]

for i in range(1,M+1):
    a,b=map(int,input().split())
    arr[a].append(b)
    indegree[b]+=1

heap=[]
for i in range(1,N+1):
    if indegree[i]==0:
        hq.heappush(heap,i)

ans=[]
while heap:
    tmp=hq.heappop(heap)
    ans.append(tmp)
    for i in arr[tmp]:
        indegree[i]-=1
        if indegree[i]==0:
            hq.heappush(heap,i)

print(*ans)