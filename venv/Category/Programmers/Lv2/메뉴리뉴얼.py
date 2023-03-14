from itertools import combinations
menu=dict()
def add(key):
    global menu
    menu[key]=menu.setdefault(key,0)+1

def findCombi(orders,course):
    for order in orders:
        if len(order)<course: continue
        arr=sorted(list(order))
        for cb in combinations(arr, course):
            cb=''.join(cb)
            add(cb)
def pop1value():
    arr=menu.copy()
    for k,v in arr.items():
        if v==1:
            menu.pop(k)
def isDuplicate(key, ans):
    dp=[0]*(len(ans)+1)
    for i in range(len(ans)):
        for j in range(len(key)):
            if ans[i]==key[j]:
                dp[i]=max(dp[i],dp[j]+1)
    if max(dp)==len(key):
        return True
    return False

visit=[0]*11
def isAlreadyIn(key, answer):
    for ans in answer:
        if isDuplicate(key,ans) and menu[key]==menu[ans]:
            return True
    return False

def getAnswer():
    answer=[]
    keys=sorted(menu.keys(),key= lambda a: a[1],reverse=True)
    for m in menu.keys():
        visit[len(m)]=max(visit[len(m)], menu[m])

    for key in keys:
        if visit[len(key)]>menu[key]:
            continue
        if isAlreadyIn(key,answer):
            continue
        answer.append(key)
    print(answer)
    return sorted(answer)
    
def solution(orders, courses):
    for course in courses:
        findCombi(orders, course)
    pop1value()
    return getAnswer()

solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],[2,3,5])