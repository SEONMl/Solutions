def solution(absolutes, signs):
    res=0
    for i in range(len(absolutes)):
        res=res + absolutes[i] if signs[i] else res-absolutes[i]
    return res
a1=[4,7,12]
s1=[True,False,True]
print(solution(a1,s1))