import sys
input=sys.stdin.readline
n,k=map(int,input().split()) # 1<=k<n<500,000
num=input().strip()
stk=[]
del_num=k
for i in range(n):
    while del_num>0 and stk:
        if stk[-1]<num[i]:
            stk.pop()
            del_num-=1
        else:
            break
    stk.append(num[i])
print(''.join(stk[:n-k]))
# k>0 인데 남은 수가 같은 수일 경우를 생각해 줘야 함.