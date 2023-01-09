import sys;input=sys.stdin.readline
N=int(input())
for _ in range(N):
    s=input().strip()
    dic=dict()
    for c in s:
        if c==' ':
            continue
        dic.setdefault(c,0)
        dic[c]+=1

    lst=sorted(dic.items(), key=lambda a:a[1], reverse=True)
    if len(lst)>1 and lst[0][1]==lst[1][1]:
        print("?")
    else:
        print(lst[0][0])