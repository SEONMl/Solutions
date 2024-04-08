MAX = 9999999999
def solution(alp, cop, problems):
    N,M = 0,0 # maxAlp, maxCop
    
    for i in problems:
        N=max(i[0], N)
        M=max(i[1], M)
    
    alp=min(N,alp)
    cop=min(M,cop)
    dp=[[MAX]*200 for i in range(200)]
    dp[alp][cop]=0
    
    for i in range(alp,N+1):
        for j in range(cop,M+1):
            if i<N:
                dp[i+1][j]=min(dp[i][j]+1, dp[i+1][j])
            if j<M:
                dp[i][j+1]=min(dp[i][j]+1, dp[i][j+1])
            
            for a,c,ar,cr,cost in problems:
                if i>=a and j>=c:
                    tmpI=min(i+ar, N)
                    tmpJ=min(j+cr, M)
                    dp[tmpI][tmpJ]=min(dp[tmpI][tmpJ], dp[i][j]+cost)
    
    return dp[N][M]
 