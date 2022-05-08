# 220508
n=int(input())
for _ in range(n):
    dic=dict()
    m=int(input())
    for i in range(m):
        a,b=input().split()
        dic[b]=dic.setdefault(b,0)+1
    cloth=list(dic.values())
    res=1
    for i in range(len(cloth)):
        res=res*(cloth[i]+1)
    print(res-1)