# 220419 정답? | 배낌, 어렵
'''
제일 짧은 길이를 start, 제일 긴 길이를 end
'''
import sys

K, N = map(int, input().split())  # 가지고 있는 랜선(길이 제각각), 필요한 랜선 수
lenK = [int(sys.stdin.readline()) for i in range(K)]
start, end = 1, max(lenK)

while start <= end:
    mid = (start+end) // 2
    cnt = 0
    for i in lenK:
        cnt += i // mid

    if (cnt >= N):  # mid가 너무 짧아서
        start=mid +1
    else:  # mid가 너무 길어서
        end = mid-1

print(end)