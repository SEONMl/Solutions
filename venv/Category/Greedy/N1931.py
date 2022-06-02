import sys
input=sys.stdin.readline
n=int(input())
cnt=0
time=[]
for i in range(n):
    time.append(list(map(int,input().split())))
time=sorted(time,key=lambda x:x[0])
time=sorted(time, key=lambda x:x[1])

last=0
for i,j in time:
    if i>=last:
        cnt+=1
        last=j
print(cnt)