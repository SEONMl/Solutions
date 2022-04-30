l = list(map(str, " ".join(input()).split()))

answer = [-1] * 26
i = 1
for c in l:
    idx = ord(c) - ord('a')
    if (answer[idx] == -1):
        answer[idx] += i
    i += 1

