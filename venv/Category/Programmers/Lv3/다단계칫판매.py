def solution(enroll, referral, seller, amount):
    profit=[0]*(len(enroll))
    hr=dict()
    parent=dict()
    for i in range(len(enroll)):
        hr[enroll[i]]=i
    for i in range(len(enroll)):
        a=-1 if referral[i]=="-" else hr[referral[i]]
        parent[i]=a
        
    for i in range(len(seller)):
        money=amount[i]*100
        cost(hr[seller[i]],parent,money,profit)
    return profit

def cost(child,parent,money,profit): # int, arr, int, arr
    send = money // 10
    mine = money - send
    if parent[child]==-1 or money<1:
        profit[child]+=mine
        return
    profit[child]+=mine
    cost(parent[child],parent,send,profit)
    return

e1=["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
r1=["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
s1=["young", "john", "tod", "emily", "mary"]
s2=["sam", "emily", "jaimie", "edward"]
a1=[12, 4, 2, 5, 10]
a2=[2,3,5,4]
print(solution(e1,r1,s1,a1))
result=[360, 958, 108, 0, 450, 18, 180, 1080]