# 220426 정답
n, k = map(int, input().split())
lst = list(map(int, input().split()))

cum = []
cum.append(sum(lst[:k]))
for i in range(0, n-k):
    tmp = cum[i] + lst[i + k] - lst[i]
    cum.append(tmp)

print(max(cum))
