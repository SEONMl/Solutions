# 220424 정답
n, k = map(int, input().split())
coin = [int(input()) for i in range(n)]  # 오름차순

rest = k
cnt = 0
i = n - 1
while rest != 0:
    cnt += rest // coin[i]
    rest = rest % coin[i]
    i -= 1

print(cnt)
