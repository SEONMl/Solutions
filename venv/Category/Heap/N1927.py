# 220420 정답 | 힙 처음 접함
import sys, heapq

N = int(input())

heap=[]
answer=[]
for i in range(N):
    tmp = int(sys.stdin.readline())
    if tmp==0:
        if heap:
            answer.append(heapq.heappop(heap))
        else:
            answer.append(0)

    else:
        heapq.heappush(heap, tmp)

for i in answer:
    print(i)
