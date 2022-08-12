import sys;input=sys.stdin.readline
T=int(input())
def check(s,e,n):
    if n==1:
        return True
    for i in range(n//2):
        if a[s]==a[e-1-i]:
            return False
        return check(s,e//2,n//2) and check(e//2+1,e,n//2)
for _ in range(T):
    a=list(' '.join(input()).split())
    if check(0,len(a),len(a)):
        print("YES")
    else:
        print("NO")