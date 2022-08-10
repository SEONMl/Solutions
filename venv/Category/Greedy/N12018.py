import sys
input=sys.stdin.readline
n,m=map(int,input().split())
res=[]
for i in range(n):
    p,l=map(int,input().split())
    mile=list(map(int,input().split()))
    mile.sort(reverse=True)
    try:
        res.append(mile[l-1])
    except Exception:
        res.append(1)
cnt,t=0,0
res.sort()
for i in res:
    t+=i
    if t<=m:
        cnt+=1
print(cnt)