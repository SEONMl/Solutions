import sys;input=sys.stdin.readline
N,M=map(int,input().split())
train=[0]*N
for _ in  range(M):
    tmp=list(map(int,input().split()))
    if len(tmp)==3:
        cmd,i,x=tmp[0],tmp[1]-1,tmp[2]-1
    else:
        cmd,i=tmp[0],tmp[1]-1

    if cmd==1:
        train[i]|=(1<<x)
    elif cmd==2:
        train[i]&=~(1<<x)
    elif cmd==3:
        train[i]<<=1
        train[i]&=~(1<<20)
    else:
        train[i]>>=1
print(len(set(train)))
