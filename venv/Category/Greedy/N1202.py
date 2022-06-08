import sys,heapq
input=sys.stdin.readline
N,K=map(int,input().split())
jewel=[list(map(int,input().split())) for i in range(N)] # [M,V]
bag=[int(input()) for i in range(K)]
jewel.sort()
bag.sort()

tmp=[]
res=0
for i in bag:
    while jewel and jewel[0][0]<=i:
        heapq.heappush(tmp,-jewel[0][1])
        heapq.heappop(jewel)
    if tmp:
        res+=heapq.heappop(tmp)
print(-res)
# 가방 용량보다 무게가 작은 보석을 tmp에 저장 (heap을 사용해 가치를 기준으로 정렬)
# ex) 용량 2 보다 작은 (1,65), (2,99) tmp에 저장 -> 99짜리 보석 선택-> 용량 10 보다 작은 (5,23) tmp에 저장 -> 65짜리 보석 선택