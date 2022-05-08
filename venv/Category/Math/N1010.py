# 220508
n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    combi=[[0]*(b+1) for i in range(b+1)]
    combi[1][0]=combi[1][1]=1
    for i in range(2,b+1):
        for j in range(i+1):
            if i==j or j==0:
                combi[i][j]=1
            if j==1:
                combi[i][j]=i
            else:
                combi[i][j]=combi[i-1][j]+combi[i-1][j-1]
                combi[i][i-j]=combi[i][j]
    print(combi[b][a])