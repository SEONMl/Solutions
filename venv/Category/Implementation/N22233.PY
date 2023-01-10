import sys;input=sys.stdin.readline
N,M=map(int,input().split()) #200,000
keyword=dict()
for i in range(N):
    keyword[input().strip()]=1
cnt=N
for _ in range(M):
    memo=list(map(str,input().strip().split(',')))
    for i in memo:
        if i in keyword.keys():
            if keyword[i]==1:
                keyword[i]-=1
                cnt-=1
    print(cnt)


# set 차집합을 사용하는 것보다 딕셔너리가 더 빠르다..?