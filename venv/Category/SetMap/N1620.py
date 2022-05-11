# 220511
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
name=idx=dict()
for i in range(n):
    tmp=input().strip()
    idx[i+1]=tmp
    name[tmp]=i+1
for i in range(m):
    tmp=input().strip()
    try:
        print(idx[int(tmp)])
    except:
        print(name[tmp])