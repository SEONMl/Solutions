# 220420 정답
# 최대힙, 최소힙 / HeapQ / Priority Queue
import sys, heapq

N=int(input())
heap=[]
answer=[]
for i in range(N):
    tmp = int(sys.stdin.readline())
    if tmp==0:
        if heap:
            answer.append(-heapq.heappop(heap))
        else:
            answer.append(0)

    else:
        heapq.heappush(heap, -tmp)

for i in answer:
    print(i)
