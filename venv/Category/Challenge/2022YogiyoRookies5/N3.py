def solution(S, C):
    mask=[0]*len(S)
    if check(S):
        return 0
    ans=0
    s,e=0,len(S)
    for c in C:
        ans+=1
        if not mask[c]:
            if check(S[s:c]):
                for j in range(s,c):
                    mask[j]=1
                s=c
            if check(S[c:e]):
                for j in range(c,e):
                    mask[j]=1
                e=c
        if sum(mask)==len(S):
            return ans
    return -1
def check(s):
    alpha=[0]*26
    for i in s:
        alpha[ord(i)-97]+=1
        if alpha[ord(i)-97]>=2:
            return False
    return True
print(solution('aabcba', [1, 3, 2]))
print(solution('aabcddcb', [3, 5, 1, 4, 7]))
print(solution('asdf', [1]))