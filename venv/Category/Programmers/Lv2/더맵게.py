import heapq
def solution(scoville,k):
    cnt=0
    heap=[]
    for i in scoville:
        heapq.heappush(heap,i)
    while heap[0]<k:
        try:
            res=heapq.heappop(heap)+heapq.heappop(heap)*2
            cnt+=1
            heapq.heappush(heap,res)
        except IndexError:
            return -1
    return cnt
print(solution([1,2,3,9,10,12],7))