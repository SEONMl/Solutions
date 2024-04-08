from itertools import combinations
menu=dict()

def findCombi(orders,course):
    for order in orders:
        if len(order)<course: continue
        arr=sorted(list(order))
        for cb in combinations(arr, course):
            cb=''.join(cb)
            menu[cb]=menu.setdefault(cb,0)+1

def pop1value():
    arr=menu.copy()
    for k,v in arr.items():
        if v==1:
            menu.pop(k)

def getAnswer():
    answer=[]
    
    visit=[0]*11
    for m in menu.keys():
        visit[len(m)]=max(visit[len(m)], menu[m])

    for key in menu.keys():
        if visit[len(key)]>menu[key]:
            continue
        answer.append(key)
    answer.sort()
    return answer
    
def solution(orders, courses):
    for course in courses:
        findCombi(orders, course)
    pop1value()
    
    return getAnswer()