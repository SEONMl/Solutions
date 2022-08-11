import sys;input=sys.stdin.readline
N,C=map(int,input().split())
home=[int(input()) for i in range(N)]
home.sort()
s,e=1,home[-1]-home[0]
res=0
while s<=e:
    # mid가 공유기 개수
    mid=(s+e)//2
    cur=home[0]
    cnt=1
    for i in range(1,N):
        if home[i]>=cur+mid:
            cnt+=1
            cur=home[i]
    if cnt>=C:
        s=mid+1
        res=mid
    else:
        e=mid-1
print(res)