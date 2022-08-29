def solution(citations):
    citations.sort()
    k=len(citations)
    for i in range(k):
        if citations[i]>=k-i:
            return k-i
    return 0

print(solution([0,3,6,5,1]))
print(solution([10,10,10,10,10,10]))