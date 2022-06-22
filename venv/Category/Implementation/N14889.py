n=int(input())
g=[list(map(int,input().split())) for i in range(n)]

def dfs(depth,idx):
    global min_diff
    if depth == n//2:
        power1,power2=0,0
        for i in range(n):
            for j in range(n):
                if visit[i] and visit[j]:
                    power1+=g[i][j]
                elif not visit[i] and not visit[j]:
                    power2+=g[i][j]
        min_diff=min(min_diff,abs(power1-power2))
        return

    for i in range(idx,n):
        if not visit[i]:
            visit[i]=1
            dfs(depth+1, i+1)
            visit[i]=0

visit=[0 for _ in range(n)]
min_diff=int(1e9)

dfs(0, 0)
print(min_diff)