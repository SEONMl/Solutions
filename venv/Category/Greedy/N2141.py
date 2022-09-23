import sys;input=sys.stdin.readline
N=int(input())
a=[list(map(int,input().split())) for i in range(N)]
a.sort()
pop=0 #인구수
for i in range(N):
    pop+=a[i][1]
mid=pop//2
if pop%2:
    mid+=1
ans=0
for i,j in a:
    ans+=j
    if ans>=mid:
        print(i)
        break

# 인구수의 누적합이 인구수의 절반이 넘어가는 곳이 제일 효율적이라는데
# 왜지... 직관의 힘인가...