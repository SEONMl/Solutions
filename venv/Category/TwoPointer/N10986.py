import sys
n,m=map(int,input().split())
a=list(map(int,sys.stdin.readline().split()))
acc=0
cnt=[0 for i in range(m)]

cnt[0]+=1 # 왜지??????????
for i in range(n):
    acc+=a[i]
    cnt[acc%m]+=1 # 나머지 개수

res=0
for i in cnt:
    res+=i*(i-1)//2 # 누적합의 나머지가 같은 것 두 개를 고르면 그 사이 합?값?들도 나눠짐 | nC2 = n*(n-1)/2
print(res)
'''
시간초과
for i in range(n-1):
    for j in range(i, n):
        if (acc[j]-acc[i]+a[i])%m==0:
            cnt+=1
'''
