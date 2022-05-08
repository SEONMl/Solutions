# 220508
n=int(input())
a=[int(input()) for i in range(n)]
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
a.sort()
for i in range(len(a)-1):
    tmp=a[i+1]-a[i]
    if i==0:
        mygcd=tmp
    mygcd=gcd(mygcd,tmp)
res=set()
for i in range(2, int(mygcd**0.5)+1):
    if mygcd%i==0:
        res.add(i)
        res.add(mygcd//i)
res.add(mygcd)
res=sorted(list(res))
print(*res)