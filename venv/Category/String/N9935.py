import sys
input = sys.stdin.readline
S=list(input().rstrip())
bomb=list(input().rstrip())
stk=[]
for i in range(len(S)):
    stk.append(S[i])
    if stk[-1]==bomb[-1] and len(stk)>=len(bomb):
        if stk[-len(bomb):]==bomb:
            for i in range(len(bomb)):
                stk.pop()
if stk:
    print("".join(stk))
else:
    print("FRULA")