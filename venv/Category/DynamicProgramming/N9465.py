import sys
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    n=int(input())
    g=[list(map(int,input().split())) for i in range(2)]
    for i in range(1,n):
        if i==1:
            g[0][i]+=g[1][i-1]
            g[1][i]+=g[0][i-1]
        else:
            g[0][i]+=max(g[1][i-1],g[1][i-2])
            g[1][i]+=max(g[0][i-1],g[0][i-2])
    print(max(g[0][n-1],g[1][n-1]))