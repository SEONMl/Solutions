# 220511
import sys

n,s=map(int,input().split())
a=list(map(int,input().split()))
prefix=[0]*n
for i in range(n-1):
    prefix[i+1]=prefix[i]+a[i]
l,r,tmp=0,0,0
mymin=sys.maxsize
while 1:
    if tmp>=s:
        mymin=min(mymin,r-l)
        tmp-=a[l]
        l+=1
    elif r==n:
        break
    else:
        tmp+=a[r]
        r+=1
if mymin==sys.maxsize:
    print(0)
else:
    print(mymin)