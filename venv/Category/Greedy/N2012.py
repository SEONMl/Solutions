import sys;input=sys.stdin.readline
n=int(input())
a=[int(input()) for i in range(n)]
a.sort()
res=0
for i in range(n):
    res+=abs(a[i]-i-1)
print(res)