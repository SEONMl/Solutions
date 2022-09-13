# N: 수업수, k: 과목의 수업시간 수, M: 학생수
# 시간 좀 더 줄일 수 있음...
import sys;input=sys.stdin.readline
N=int(input())
k=[set(list(map(int,input().split()))[1:]) for i in range(N)]
M=int(input())
for _ in range(M):
    p=set(list(map(int,input().split()))[1:])
    cnt=0
    for i in range(N):
        if p&k[i]==k[i]:
            cnt+=1
    print(cnt)