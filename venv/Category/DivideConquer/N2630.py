# 220420 정담? | 배낌 복습 필요@@@@@@@@@@@@@@@@ 재귀, D&Q
import sys

n = int(input())
lst = [list(map(int, sys.stdin.readline().split())) for i in range(n)]

cnt = [0, 0]


def DQ(arr, x, y, k):
    color = arr[x][y]
    dx = k // 2
    dy = k // 2
    for i in range(x, x + k):
        for j in range(y, y + k):
            if (arr[i][j] != color):
                DQ(arr, x, y, k // 2)
                DQ(arr, x, y + dy, k // 2)
                DQ(arr, x + dx, y, k // 2)
                DQ(arr, x + dx, y + dy, k // 2)
                return # 이게 중요? @@@@@@@@@@@@@@@@@@@@@@@@@@
    if color == 0:
        cnt[0] += 1
    else:
        cnt[1] += 1


DQ(lst, 0, 0, n)
for i in cnt:
    print(i)
