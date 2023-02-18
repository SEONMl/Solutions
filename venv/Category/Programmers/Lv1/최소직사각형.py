def solution(sizes):
    w,h=[],[]
    for i in range(len(sizes)):
        w.append(max(sizes[i]))
        h.append(min(sizes[i]))
    return max(w)*max(h)

print(solution([[60, 50], [30, 70], [60, 30], [80, 40]]))