from math import factorial
n=int(input())
res=str(factorial(n))[::-1]
cnt=0
for c in res:
    if c=="0":
        cnt+=1
    else:
        break
print(cnt)