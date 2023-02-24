import sys;input=sys.stdin.readline

def isSubsequence(s,t):
    s_idx=0
    for ch in t:
        if ch==s[s_idx]:
            s_idx+=1
        if s_idx==len(s):
            return True
    return False

while 1:
    try:
        s,t=map(str,input().strip().split())
        print("Yes") if isSubsequence(s,t) else print("No")
    except:
        break