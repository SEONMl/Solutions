import sys
input=sys.stdin.readline
N,C=map(int,input().split())
M=int(input())
lst=[list(map(int,input().split())) for i in range(M)]
lst=sorted(lst,key=lambda a:a[1])
tmp=[C]*N
res=0
for i in range(M):
    mmin=C
    for j in range(lst[i][0],lst[i][1]):
        if tmp[j]<=mmin:
            mmin=tmp[j]
    t=min(mmin,lst[i][2])
    res+=t
    for j in range(lst[i][0],lst[i][1]):
        tmp[j]-=t
print(res)