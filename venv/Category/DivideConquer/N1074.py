import sys
input=sys.stdin.readline
k,r,c=map(int,input().split())
t=0
while k>0:
    tmp=2**(k-1)
    if r<tmp and c<tmp:
        t+=0
    elif r<tmp and c>=tmp:
        t+=tmp**2
        c-=tmp
    elif tmp<=r and c<tmp:
        t+=tmp**2*2
        r-=tmp
    elif tmp<=r and c>=tmp:
        t+=tmp**2*3
        r-=tmp
        c-=tmp
    k-=1
print(t)