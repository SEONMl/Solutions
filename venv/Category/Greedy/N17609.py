import sys;input=sys.stdin.readline
T=int(input())
def pseudo(s,l,r):
    while l<r:
        if s[l]==s[r]:
            l+=1
            r-=1
        else:
            return False
    return True
def check(s,l,r):
    if s==s[::-1]:
        return 0
    else:
        while l<r:
            if s[l]!=s[r]:
                check1=pseudo(s,l+1,r)
                check2=pseudo(s,l,r-1)
                if check1 or check2:
                    return 1
                else:
                    return 2
            else:
                l+=1
                r-=1
for _ in range(T):
    tmp=input().rstrip()
    print(check(tmp,0,len(tmp)-1))