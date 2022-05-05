# 시간초과 | 제출은 c++로 함
# 백트래킹은 파이썬과 맞지 않음
n=int(input())
g=[0]*n # 행 : 인덱스, 열 : 값
cnt=0
def isAdj(x):
    for i in range(x):
        if g[x]==g[i] or abs(g[x]-g[i])==x-i:
            return False
    return True

def dfs(idx):
    if idx==n:
        global cnt
        cnt+=1
        return

    for i in range(n):
        g[idx] = i
        if isAdj(idx):
            dfs(idx+1)
dfs(0)
print(cnt)

