import math
n=int(input())
m=int(input())
def isPrime(num):
    if num==1:
        return False
    for i in range(2,int(math.sqrt(num))+1):
        if num%i==0:
            return False
    return True
res=[]
for i in range(n,m+1):
    if isPrime(i):
        res.append(i)

if res:
    print(sum(res))
    print(res[0])
else:
    print(-1)