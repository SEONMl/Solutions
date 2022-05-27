from collections import deque
def solution(n, computers):
    visit=[0]*n
    cnt=0
    for i in range(n):
        if visit[i]==0:
            cnt+=1
            bfs(computers,i,visit)
    return cnt

def bfs(arr,start,visit):
    q=deque()
    visit[start]=1
    q.append(start)
    while q:
        t=q.popleft()
        for i in range(len(arr[t])):
            if visit[i]==0 and arr[t][i]:
                visit[t]=1
                q.append(i)

n=3
c=[[1, 1, 0], [1, 1, 0], [0, 0, 1]]
c1=[[1, 1, 0], [1, 1, 1], [0, 1, 1]]
print(solution(n,c1))