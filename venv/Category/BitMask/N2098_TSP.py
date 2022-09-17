import sys;input=sys.stdin.readline
N=int(input())
g=[list(map(int,input().split())) for i in range(N)]
INF=float('inf')
dp=[[0]*(1<<N-1) for i in range(N)]
def tsp(i, k):
    if dp[i][k]!=0:
        return dp[i][k]
    if k==(1<<(N-1))-1: # 모든 지점 방문
        return g[i][0] if g[i][0] else INF
    tmp=INF
    for j in range(1,N): # 모든 지점 탐방
        if not g[i][j]: continue # 가는 경로가 없을 때
        if k&(1<<j-1): continue # 이미 방문한 도시일 때
        tmp=min(tmp,g[i][j]+tsp(j,k|(1<<(j-1))))
        dp[i][k]=tmp
    return tmp
print(tsp(0,0))

'''
외판원 순회(TSP, 조합 최적화)
: 도시의 개수와 각 도시 쌍 간의 거리들이 주어질 때, 모든 도시를 한 번씩 방문하고 
  여행을 시작한 원래 도시로 돌아올 수 있는 최단거리 경로를 구하는 알고리즘
  
★★★★★ n개의 정점 중 어느 정점에서 탐색을 시작해도 결과는 똑같다 ★★★★★
float('inf') : 양의 무한대
float('-inf') : 음의 무한대

인덱스 1번부터 시작하면 시간초과
인덱스 0번부터하면 정답...
비트마스킹이라도 인덱스 0번으로 시작하기
'''