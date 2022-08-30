import heapq
def solution(scoville, K):
    cnt=0
    heap=[]
    for i in scoville:
        heapq.heappush(heap,i)
    while heap[0]<K:
        min1=heapq.heappop(heap)
        if not heap:
            return -1
        min2=heapq.heappop(heap)
        heapq.heappush(heap,min1+min2*2)
        cnt+=1
    return cnt


print(solution([1,3,2,9,10,12],7))
#print(solution([1,3,2,9,10,12],1000))
print(solution([0,0,0,0,0,1,3,2,9,10,12],12))