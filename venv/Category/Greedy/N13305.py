n = int(input())
d = list(map(int, input().split()))  # distance | n-1
p = list(map(int, input().split()))  # price | n

cost = 0
for i in range(n):
    k = 1
    while p[i] <= p[i + k] and i + k < n:
        cost += p[i] * d[i + k - 1]
        k += 1
        if i+k==n:
            break
    i = i + k-1
print(cost)
