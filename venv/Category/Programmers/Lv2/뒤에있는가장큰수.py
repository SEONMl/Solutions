import heapq as hq

def solution(numbers):
    n=len(numbers)
    ans=[-1]*n
    h=[]
    for i in range(n):
        cur=numbers[i]

        while h and h[0][0]<cur:
            num,idx=hq.heappop(h)
            ans[idx]=cur
        hq.heappush(h, [cur,i])

    return ans

solution([2,3,3,5])
solution([9,1,5,3,6,2])