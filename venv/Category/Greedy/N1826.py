import sys
import heapq
input=sys.stdin.readline
n = int(input())
ab = []
[heapq.heappush(ab, list(map(int, input().split()))) for _ in range(n)]
l, p = map(int, input().split())
cnt = 0
heap = []

# 현재 있는 연료로 마을까지 갈수 있을 때까지 반복
while p < l:

    # 앞으로 주유소가 있고 다음 주유소를 현재 연료로 갈 수 있으면
    # 현재 연료로 갈 수 있는 모든 주유소를 확인
    while ab and ab[0][0] <= p:
        # 주유소의 연료양 기준으로 최대힙을 만들어 리스트에 푸시한다.
        a, b = heapq.heappop(ab)
        heapq.heappush(heap, [-b, a])

    # 현재 연료로 다음 주유소까지 갈 수 없으므로 -1 출력
    if not heap:
        cnt = -1
        break

    # 최대힙을 팝한다.(연료를 제일 많이 충전해주는 주유소)
    b, a = heapq.heappop(heap)
    # 연료를 충전한다.
    p += -b
    cnt += 1
print(cnt)