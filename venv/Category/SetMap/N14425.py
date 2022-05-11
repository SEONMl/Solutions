n,m=map(int,input().split())
S=set()
for i in range(n):
    tmp=input()
    S.add(tmp)
cnt=0
for i in range(m):
    tmp=input()
    if tmp in S:
        cnt+=1
print(cnt)