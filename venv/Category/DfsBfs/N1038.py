from collections import deque
n=int(input())
# 0 1 2 3... 10 20 21 30 31 32 40 41 42(18)
# 9876543210 <- 감소하는 수 최댓값
q=deque([0,1,2,3,4,5,6,7,8,9])
if n<10:
    print(n)
    exit(0)
cnt=9
while q:
    tmp=q.popleft()
    for i in range(10):
        if int(str(tmp)[-1])<=i: break
        q.append(int(str(tmp)+str(i)))
        cnt+=1
        if cnt==n:
            print(q[-1])
            exit(0)
print(-1)