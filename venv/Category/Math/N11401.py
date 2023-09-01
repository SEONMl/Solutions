N,K=map(int,input().split())
MOD=1_000_000_007

factorial = [1 for i in range(N+1)]
for i in range(2,N+1):
    factorial[i]=(factorial[i-1]*i) % MOD # N! % MOD

def power(a,b):
    if b==0: return 1
    if b%2:
        return (power(a,b-1)*a) % MOD
    tmp=power(a,b//2) % MOD
    return tmp*tmp % MOD

a=power(factorial[K]*factorial[N-K], MOD-2) # K! * (N-K)!
print((factorial[N]*a) % MOD)