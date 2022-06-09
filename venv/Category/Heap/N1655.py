import heapq,sys
input=sys.stdin.readline
n=int(input()) # n>=1
right=[] # min heap
left=[] # max heap
# -left[0] right[0] tmp 비교
for i in range(n):
    tmp=int(input())

    if len(left)==len(right):
        heapq.heappush(left,-tmp)
    else:
        heapq.heappush(right,tmp)

    if right and -left[0]>right[0]:
        tmp_left=-heapq.heappop(left)
        tmp_right=heapq.heappop(right)
        heapq.heappush(right,tmp_left)
        heapq.heappush(left,-tmp_right)

    print(-left[0])