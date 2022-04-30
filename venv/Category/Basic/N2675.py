n = int(input())
for j in range(n):
    r, s = map(str, input().split())
    for i in s:
        print(i * int(r), end="")
    print()