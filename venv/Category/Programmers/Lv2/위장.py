def solution(clothes):
    dic=dict()
    for i,j in clothes:
        dic.setdefault(j,0)
        dic[j]+=1
    tmp=1
    for i in dic.values():
        tmp*=(i+1)
    tmp-=1
    return tmp

print(solution([["yellow_hat", "headgear"],
                ["blue_sunglasses", "eyewear"],
                ["green_turban", "headgear"]])) # 5