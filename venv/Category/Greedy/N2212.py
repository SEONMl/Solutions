import sys;input=sys.stdin.readline
N=int(input())
K=int(input())
if K>=N:
    print(0)
    exit(0)
arr=list(map(int,input().split()))
arr.sort()
d=[]
for i in range(1,N):
    d.append(arr[i]-arr[i-1])
d.sort()
for i in range(K-1):
    d.pop()
print(sum(d))