# 220511
import sys
input=sys.stdin.readline
n=int(input())
had=set(list(map(int,input().split())))
m=int(input())
find=list(map(int,input().split()))
for i in find:
    if i in had:
        res=1
    else:
        res=0
    print(res,end=" ")