import sys
input=sys.stdin.readline
N,M=map(int,input().split())
a=list(map(int,input().split()))
s,e=max(a),sum(a)
ans=sys.maxsize
while s<=e:
    mid=(s+e)//2
    summ,cnt=0,0
    for i in range(N):
        if summ+a[i]>mid:
            cnt+=1
            summ=0
        summ+=a[i]
    if summ:
        cnt+=1

    if cnt>M:
        s=mid+1
    else:
        ans=min(mid,ans)
        e=mid-1
print(ans)