import sys
input=sys.stdin.readline
N=int(input())
tmp=list(map(int,input().split()))
max_dp=tmp
min_dp=tmp
for i in range(1,N):
    a,b,c=map(int,input().split())
    max_dp=[a+max(max_dp[0],max_dp[1]),b+max(max_dp),c+max(max_dp[1],max_dp[2])]
    min_dp=[a+min(min_dp[0],min_dp[1]),b+min(min_dp),c+min(min_dp[1],min_dp[2])]

print(max(max_dp), min(min_dp))

'''
메모리 4MB
DP에서 말하는 슬라이딩 윈도우 기법이란, 메모이제이션을 할 때 더 이상 사용하지 않는 값을 저장하지 않고 배열을 계속하여 갱신해주는 것을 의미한다.
앞으로 쓰이지 않을 값이 메모이제이션되지 않으므로 당연히 배열은 최소한의 상태로 유지되고, 자연스레 메모리 사용량이 감소한다.
'''