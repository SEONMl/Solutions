def solution(m, n, puddles):
    road=[[0]*(n+1) for i in range(m+1)]

    for i in range(1,m+1):
        for j in range(1,n+1):
            if i==1 and j==1:
                road[1][1] = 1
            elif [i,j] not in puddles:
                    road[i][j]=road[i-1][j]+road[i][j-1]

    return road[m][n]%1000000007


p=[[2,2]]
print(solution(4,3,p)) # 4
#오른쪽 아래쪽으로만 이동, 최단경로의 개수 % 1000000007 리턴
