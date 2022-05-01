from collections import deque
n,k=map(int,input().split())
max=10**5
# 이게 왜 bfs? 어떻게 큐로 구현하지?
# 방법 3가지 1. x+1 2. x-1 3. 2*x
# 여러 해 구하고 최솟값 출력?
q=deque()
q.append(n)
d=[0]*(max+1)

while 1:
    t=q.popleft()
    if t==k:
        print(d[t])
        break
    for i in (t-1,t+1,2*t):
        if 0<=i<=max and not d[i]:
            d[i]=d[t]+1
            q.append(i)