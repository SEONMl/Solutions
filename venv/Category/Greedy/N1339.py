import sys
input=sys.stdin.readline
n=int(input())
s=[]
dic=dict()
for i in range(n):
    t=input().strip()
    a=len(t)
    for j in range(len(t)):
        dic[t[j]]=dic.setdefault(t[j],0)+10**(a-1)
        a-=1
    s.append(t)
lst=list(dic.items())
lst=sorted(lst,key=lambda a:a[1],reverse=True)
atoi=dict()
a=0
for i,j in lst:
    atoi[i]=str(9-a)
    a+=1
res=0
for i in range(n):
    t=""
    for j in s[i]:
        t+=atoi[j]
    res+=int(t)
print(res)