# 슬라이싱은 효율성 똥망, 딕셔너리 사용하기
import sys
def solution(gems):
    N=len(set(gems))
    res=[-sys.maxsize,sys.maxsize]
    s,e=0,0
    dic={gems[0]:1}
    while 0<=s<len(gems) and 0<=e<len(gems):
        if len(dic)<N:
            e+=1
            if e==len(gems):
                break
            dic[gems[e]] = dic.get(gems[e], 0) + 1

        else:
            if e-s<res[1]-res[0]:
                res=[s+1,e+1]
            if dic[gems[s]]==1:
                del dic[gems[s]]
            else:
                dic[gems[s]]-=1
            s+=1
    return res


g1=["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
g2=["AA", "AB", "AC", "AA", "AC"]
g3=["XYZ", "XYZ", "XYZ"]
print(solution(g1))