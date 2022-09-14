# 어렵군..
import sys;input=sys.stdin.readline
n,m=map(int,input().split())
p=[0]*(m+1)
for i in range(m):
    tmp=list(map(int,input().split()))
    for j in range(tmp[0]):
        p[i]|=1<<tmp[j+1]
for i in range(1,m+1):
    tmp=set()
    for j in range(len(p)):
        if p[j]==(1<<(n+1))-2:
            print(i)
            exit()
        for k in range(j+1,len(p)):
            tmp.add(p[j]|p[k])
    p=list(tmp)
print(-1)