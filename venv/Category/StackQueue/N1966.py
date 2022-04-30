# 220418
from collections import deque

N = int(input())
# <- [ queue ] <-
for i in range(N):
    n, k = map(int, input().split())  # n : 문서개수, k : 궁금한 문서
    impt = deque(map(int, input().split()))  # 중요도 클수록 높음
    docu = deque([i for i in range(n)])
    idx=k
    cnt=0
    while True:
        while impt[0] >= max(impt):
            tmp = impt.popleft()
            impt.append(tmp)

        if idx==0:
            print(cnt)
        impt.pop()
