def solution(S):
    length=len(S)
    target=S+S
    answer=0
    for i in range(length):
        start=target[i]
        end=target[i+length-1]
        if start==end:
            answer+=1
    return answer

print(solution("ana")) # anaana aba baa aab
print(solution("aaaa"))
print(solution("abaa"))

print(solution("abbaaaaaaaaaaaaaaaaaabababababbbbbabbaaaabbabababababaaaaaaabababaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbabababbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbabbababababbananannananananannnnnnn"))
