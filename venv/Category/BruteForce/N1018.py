import sys
input=sys.stdin.readline
n,m=map(int,input().split()) # n*m
arr=[] # i+j : 짝수끼리(==[0][0]) 홀수끼리 같은 색
res=sys.maxsize
def check(arr,x,y):
    b1,w1,b2,w2=0,0,0,0
    for i in range(8):
        for j in range(8):
            if (i+j)%2: # 홀수
                b1+=1 if arr[x+i][y+j]=="B" else 0
                w1+=1 if arr[x+i][y+j]=="W" else 0
            else: # 짝수
                b2+=1 if arr[x+i][y+j]=="B" else 0
                w2+=1 if arr[x+i][y+j]=="W" else 0
    mmax=max(b1+w2, b2+w1)
    return 64-mmax

for i in range(n):
    arr.append(list(map(str,' '.join(input()).split())))
for i in range(n-7):
    for j in range(m-7):
        res=min(res,check(arr,i,j))
print(res)