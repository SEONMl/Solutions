N,K,M=map(int,input().split())

factorial = [1 for i in range(N+1)]
for i in range(2,N+1):
    factorial[i]=(factorial[i-1]*i) % M

def power(n,k):
    # global M
    if k==0: return 1
    if k%2:
        return (n*power(n,k-1)) % M
    half=power(n, k//2) % M
    return (half*half) % M

bunmo= factorial[N]
bunja= power(factorial[N]*factorial[N-K], M-2) % M
print((bunmo*bunja) % M)