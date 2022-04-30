# 220420 정답? | 구간합 -> 합 누적을 배열에 저장

import sys

N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

s = [0] * (N+1)
for i in range(N):
    s[i + 1] += s[i] + arr[i]

for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())
    print(s[j]-s[i-1])