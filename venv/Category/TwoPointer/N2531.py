import sys;input=sys.stdin.readline
N,d,k,c=map(int,input().split())
sushi=[int(input()) for i in range(N)]
cupon=set()
cupon.add(c)
ans=0
sushi=sushi*2
for i in range(N):
    ate=set(sushi[i:i+k])
    ans=max(ans,len(ate.union(cupon)))
    if ans==k+1:
        break
    
print(ans)