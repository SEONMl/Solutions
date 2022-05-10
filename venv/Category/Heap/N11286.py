# 220510
import sys,heapq
n=int(input())
pos_q=[]
neg_q=[]
for i in range(n):
    x=int(sys.stdin.readline())
    if x>0:
        heapq.heappush(pos_q,x)
    elif x<0:
        heapq.heappush(neg_q,-x)


    else: # x==0 절댓값이 작은 값 출력 후 제거, 비어있으면 0 출력
        if not pos_q and not neg_q:
            tmp=0
        elif pos_q and not neg_q: # 1, -1 이면 -1부터 출력 | 1 -2이면 1 출력
            tmp=heapq.heappop(pos_q)
        elif neg_q and not pos_q:
            tmp=-heapq.heappop(neg_q)
        else:
            if abs(neg_q[0])<=pos_q[0]:
                tmp=-heapq.heappop(neg_q)
            else:
                tmp=heapq.heappop(pos_q)
        print(tmp)