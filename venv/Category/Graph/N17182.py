import sys;input=sys.stdin.readline
sys.setrecursionlimit(10**6)
N,K=map(int,input().split())
T=[list(map(int,input().split())) for i in range(N)]
INF=float('inf')
dp=[[INF]*(1<<N) for i in range(N)]
def sol(n,k):
    if k==(1<<N)-1:
        return 0
    if dp[n][k]!=INF:
        return dp[n][k]
    for i in range(N):
        if k&(1<<i)==0:
            dp[n][k]=min(dp[n][k],sol(i,k|(1<<i))+T[n][i])
    return dp[n][k]

for i in range(N):
    for j in range(N):
        for k in range(N):
            T[i][j]=min(T[i][j],T[i][k]+T[k][j])
print(sol(K,1<<K))