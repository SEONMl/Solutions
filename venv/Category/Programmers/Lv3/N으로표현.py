def solution(N,number):
    dp=[set() for i in range(9)]
    for i in range(1,9):
        dp[i].add(int(str(N)*(i)))
        for j in range(1,i):
            for k in dp[j]:
                for l in dp[i-j]:
                    dp[i].add(k+l)
                    dp[i].add(k-l)
                    dp[i].add(k*l)
                    if l:
                        dp[i].add(k//l)
            if number in dp[i]:
                return i
    else:
        return -1

print(solution(5,12))
print(solution(2,1112312312312))
print(solution(2,11))
