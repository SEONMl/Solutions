import sys;input=sys.stdin.readline
m,n=map(int,input().split())
def isPrime(k):
    if k==1:
        return False
    for i in range(2,int(k**0.5+1)):
        if (k%i==0):
            return False
    return True
for i in range(m,n+1):
    if isPrime(i):
        print(i)