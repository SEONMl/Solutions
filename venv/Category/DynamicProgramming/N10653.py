#python 시간초과 | dist도 메모라이징 하는 게 훨씬 빠름
import sys;input=sys.stdin.readline
N,K=map(int,input().split())
point=[list(map(int,input().split())) for i in range(N)]
INF=float('inf')
dp=[[INF]*N for i in range(K+1)]
def dist(x,y):
    return abs(x[0]-y[0])+abs(x[1]-y[1])
dp[0][0]=0
for i in range(1,N):
    dp[0][i]=dp[0][i-1]+dist(point[i],point[i-1])

for j in range(1,K+1):
    dp[j][0]=0
    dp[j][1]=dp[j-1][1]
    dp[j][j]=dist(point[0],point[j])
    for i in range(1,N):
        for k in range(j,0,-1):
            if i-k-1<0: continue
            dp[j][i]=min(dp[j][i],dp[j-k][i-k-1]+dist(point[i],point[i-k-1]),dp[j][i-1]+dist(point[i],point[i-1]))

print(dp[-1][-1])