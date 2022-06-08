import heapq,sys
input=sys.stdin.readline
n=int(input())
h=[]
for i in range(n):
    heapq.heappush(h,int(input()))
res=0
while len(h)>1:
    a=heapq.heappop(h)
    b=heapq.heappop(h)
    res+=a+b
    heapq.heappush(h,a+b)
print(res)
# 1 2 3 / 3 3 / 6
# 1 2 3 4 / 3 3 4 / 4 6 / 10