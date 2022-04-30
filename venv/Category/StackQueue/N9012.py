# 220418 정답
n=int(input())


answer=[]

for i in range(n):
    tmp=list(map(str, " ".join(input()).split()))

    vps = []
    for j in tmp:
        if j =="(":
            vps.append("(")
        else:
            if vps and vps[-1]=="(":
                vps.pop()
            else:
                vps.append(")")

    if not vps:
        answer.append("YES")
    else:
        answer.append("NO")

for i in answer:
    print(i)