import sys
sys.setrecursionlimit(10**6)
def solution(n, m, x, y, r, c, k):
    dx=[1,0,0,-1]
    dy=[0,-1,1,0]
    idx={0:'d',1:'l',2:'r',3:'u'}
    g=[["."]*(m+1) for i in range(n+1)]
    g[r][c]="E"
    ans=[]
    result=["impossible"]
    def dfs(tmp,s,e):
        if result[0]!='impossible' and tmp>result[0]:
            return
        if g[s][e]=="E" and len(tmp)==k :
            result[0]=min(result[0],tmp)
            return
        if len(tmp)>=k:
            return
        for i in range(4):
            nx,ny=s+dx[i],e+dy[i]
            if 1<=nx<=n and 1<=ny<=m:
                dfs(tmp+idx[i],nx,ny)
    dfs("",x,y)
    return result[0]
print("dd">"daa")
print(solution(3, 4, 2, 3, 3, 1, 5))
print(solution(2, 2, 1, 1, 2, 2, 2))
print(solution(3, 3, 1, 2, 3, 3, 4))
# 좌우상하
#중복방문 ㅇ
# x,y start
# r,c end
# 시간 초과