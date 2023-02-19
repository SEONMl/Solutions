import math
prime=[True]*10000000
cnt=set()
def primeChae(n):
    N=10**n
    prime[0]=prime[1]=False
    for i in range(2,int(math.sqrt(N))+1):
        if prime[i]==0: continue
        for j in range(i+i,N,i):
            prime[j]=False
def dfs(arr,visit,n):
    global cnt
    if prime[n]:
        cnt.add(n)

    if len(str(n))==len(arr):
        return
    for i in range(len(arr)):
        if visit[i]: continue
        visit[i]=True
        dfs(arr, visit, n*10+arr[i])
        visit[i]=False
def solution(numbers):
    global cnt
    num=[]
    for i in numbers:
        num.append(int(i))

    primeChae(len(num))
    visit=[False]*len(num)
    dfs(num, visit, 0)
    print(cnt)
    return len(cnt)


print(solution('011'))