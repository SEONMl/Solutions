import sys;input=sys.stdin.readline
from collections import deque
T=int(input())
MAX=10_000
prime=[True]*MAX

def prime_chae():
    prime[0]=prime[1]=False
    for i in range(2,int(MAX**0.5)+1):
        if not prime[i]: continue
        for j in range(i+i,MAX,i):
            prime[j]=False

def bfs(start,end):
    q=deque()
    q.append([start,0])
    visit=[False]*MAX
    visit[start]=True
    while q:
        num, k=q.popleft()
        if num==end:
            return k
        
        for i in range(4):
            for j in range(10):
                nextNum=int(str(num)[:i]+str(j)+str(num)[i+1:])
                if(1000<=nextNum<10000 and prime[nextNum] and not visit[nextNum]):
                    visit[nextNum]=True
                    q.append([nextNum, k+1])
    return -1

prime_chae()
for _ in range(T):
    a,b=map(int,input().strip().split())
    ans=bfs(a,b)
    if ans==-1: print("Impossible")
    else: print(ans)