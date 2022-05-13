n,k=map(int,input().split())
obj=[]
for i in range(n):
    w,v=map(int,input().split())
    obj.append((w,v))

dp=[[0]*(k+1) for i in range(n+1)]
for p in range(1,n+1):
    for q in range(1,k+1):
        w=obj[p-1][0]
        v=obj[p-1][1]
        if q-w>=0:
            dp[p][q]=max(dp[p][q],dp[p][q-w]+v)
        else:
            dp[p][q]=dp[p][q-1]
print(dp)

'''
dp=[[0]*(k+1) for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,k+1):
        w=obj[i-1][0]
        v=obj[i-1][1]

        if j<w:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-w]+v)
print(dp[n][k])
'''