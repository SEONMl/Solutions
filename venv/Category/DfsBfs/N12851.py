# 2차원배열로 코드 짜는 연습
import sys
from collections import deque
n,k=map(int,input().split())
visit=[[-1,0] for i in range(100001)] # visit[위치][걸린시간,방문횟수]
def bfs(start):
    q=deque([start])
    visit[n][0]=0
    visit[n][1]=1
    while q:
        t=q.popleft()
        for i in (t+1,t-1,t*2):
            if 0<=i<=100000:
                if visit[i][0]==-1:
                    visit[i][0]=visit[t][0]+1
                    visit[i][1]=visit[t][1]
                    q.append(i)
                elif visit[i][0]==visit[t][0]+1:
                    visit[i][1]+=visit[t][1]
bfs(n)
print(visit[k][0])
print(visit[k][1])