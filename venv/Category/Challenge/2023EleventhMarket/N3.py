def solution(S, C):
    N=len(S)
    S+="Z"
    C.append(0)
    memo=[C[0], C[0]] # 연속된 문자 비용합, 그 중 최고 비용
    answer=0
    prev=0
    for i in range(1,N+1):
        if S[prev]!=S[i]:
            prev=i
            answer+= memo[0]-memo[1]
            memo=[C[i],C[i]]
        else:
            memo[0]+=C[i]
            memo[1]=max(memo[1], C[i])
    return answer
print(solution("abccbd", [0,1,2,3,4,5]))
print(solution("aaaa", [3,4,5,6]))
print(solution("aaaa", [3,4,5,6]))

print(solution("a", [3,4,5,6]))
# 최소 삭제 비용
# two identical letters next to each other
# 10만
# 이웃한 글자 없게 만들 건데, 최소 비용으로
# 이웃하면 최고 비용만 빼고 sum / sum-maximum