import sys,heapq
input=sys.stdin.readline
n=int(input())
lst=[list(map(int,input().split())) for i in range(n)]
lst.sort()
q=[]
for i in lst:
    heapq.heappush(q,i[1])
    if i[0]<len(q):
        heapq.heappop(q)

print(sum(q))