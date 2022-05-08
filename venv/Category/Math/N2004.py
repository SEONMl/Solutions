# 220508

b,a=map(int,input().split())
# 와우... 팩토리얼한 값에서 k로 나눠지는 개수
def isIn(n,k):
    cnt=0
    while n!=0:
        n=n//k
        cnt+=n
    return cnt
two=isIn(b,2)-isIn(b-a,2)-isIn(a,2)
five=isIn(b,5)-isIn(b-a,5)-isIn(a,5)

print(min(two,five))

'''
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
cnt=0
for c in str(combi[b][a])[::-1]:
    if c=="0":
        cnt+=1
    else:
        print(cnt)
        break
'''