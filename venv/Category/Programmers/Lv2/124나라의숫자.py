def solution(n):
    res=''
    while n:
        if n%3:
            res+=str(n%3)
            n//=3
        else:
            res+="4"
            n=n//3-1
    return res[::-1]
print(solution(10)) # 41