# chr(-아스키코드--) & ord(-문자-)
import sys;input=sys.stdin.readline
from itertools import combinations
N,K=map(int,input().split())
must={'a','n','t','i','c'}
word=set(chr(i) for i in range(97,123))-must
s=[set(input().rstrip()[4:-4])-must for i in range(N)] # a, n, t ,i, c
ans=0
if K<=4:
    print(0)
    eixt(0)
for i in list(combinations(word,K-5)):
    cnt=0
    for j in s:
        if not set(j)-set(i):
            cnt+=1
    ans=max(ans,cnt)
print(ans)
