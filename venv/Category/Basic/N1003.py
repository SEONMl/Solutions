n = int(input())
memory=[]

def isPrime(n):
    for i in range(2,n-1):
        if(n%i==0):
            memory.append(n)
            return False
    return True

m=list(map(int, input().split()))
cnt=0
for i in m:
    if(i in memory or i ==1):
        continue
    if isPrime(i):
        cnt+=1
print(cnt)
