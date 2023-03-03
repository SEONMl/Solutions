def solution(s):
    s=s.rstrip("}").lstrip("{").split("},{")
    tups=[]
    for arr in s:
        tups.append(list(map(int,arr.split(","))))
    tups.sort(key= lambda a:len(a))
    
    answer = []
    prev=set(tups[0])
    answer.append(tups[0][0])
    for i in range(1,len(tups)):
        cur=set(tups[i])
        answer.append(cur.difference(prev).pop())
        prev=cur
    return answer