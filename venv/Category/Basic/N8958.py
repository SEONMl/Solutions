n=int(input())
for _ in range(n):
    s=str(input())
    tmp=res=0
    for i in s:
        if i=="X":
            tmp=0
        else:
            tmp+=1
            res+=tmp
    print(res)
