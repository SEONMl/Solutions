import heapq as hq

def solution(food_times, k):
    heap=[]
    for i,v in enumerate(food_times):
        hq.heappush(heap, (v,i+1))

    prev=0
    answer=-1
    while heap:
        size=len(heap)

        tmp=size*(heap[0][0]-prev)
        if k>=tmp:
            k-=tmp
            prev=hq.heappop(heap)[0]
            size-=1
        else:
            idx=k%size
            heap.sort(key= lambda a:a[1])
            answer=heap[idx][1]
            break

    return answer

print(solution([3,1,2],5))
print(solution([1,3,5,3,1,2],10))