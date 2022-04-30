s=input().lower()
dic={}
for c in s:
    dic[c]=dic.get(c,0)+1

maxValue=max(dic.values())
copyy=dic.copy()
for k,v in dic.items():
    if maxValue>v:
        copyy.pop(k)

if len(copyy)==1:
    print(copyy.popitem()[0].upper())
else:
    print("?")