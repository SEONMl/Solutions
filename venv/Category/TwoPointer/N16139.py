# 알파벳 개수 = 26개 | 아스키->문자 : chr() | 문자->아스키 : ord()
import sys
s=sys.stdin.readline().strip()
n=int(input())
eng=[[0 for j in range(len(s))] for i in range(26)]
eng[ord(s[0])-97][0]=1
for i in range(1,len(s)):
    idx=ord(s[i])-ord('a')
    eng[idx][i]=1
    for j in range(26):
        eng[j][i]+=eng[j][i-1]

for _ in range(n):
    a,l,r=map(str,sys.stdin.readline().split())
    l,r=int(l),int(r)
    idx=ord(a)-ord('a')
    if l>0:
        print(eng[idx][r]-eng[idx][l-1])
    else:
        print(eng[idx][r])