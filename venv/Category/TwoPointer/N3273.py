# 220420 정답 | ?/??복습 필요
import sys

N = int(input())
arr = list(map(int, sys.stdin.readline().split()))
x = int(input())

i, j = 0, N-1
arr.sort()
cnt=0
while i<j:
    if (arr[i] + arr[j] == x):
        cnt += 1
        i += 1
    elif arr[i] + arr[j] > x:
        j -= 1
    else:
        i += 1

print(cnt)
