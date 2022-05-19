import sys

n=int(input())
block=list(map(str,' '.join(input()).split()))
dp=[sys.maxsize]*n
word={"B":0, "O":1, "J":2}
dp[0]=0
for i in range(n):
    for j in range(i+1,n):
        tmp=word[block[i]]-word[block[j]]
        if tmp==-1 or tmp==2:
            dp[j]=min(dp[j],dp[i]+(j-i)**2)
if dp[n-1]==sys.maxsize:
    print(-1)
else:
    print(dp[n-1])