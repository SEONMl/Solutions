def solution(s):
    n=len(s)
    cnt=1
    for i in range(n):
        for j in range(i+2,n+1):
            arr=s[i:j]
            if len(arr)<cnt:
                continue
            if arr==arr[::-1]:
                cnt=max(cnt,j-i)
    return cnt

print(solution("abcdcba")) #7
print(solution("abacde")) #3
print(solution("aaaaac")) #3
# for문이 복잡할 땐 슬라이스가 도움이 된다...