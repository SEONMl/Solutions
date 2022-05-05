import sys
n=int(input())
num=list(map(int,input().split()))
add,dif,mul,div = (map(int,input().split()))
totalOper=len(num)-1
mymax=-sys.maxsize
mymin=sys.maxsize
tmpmin=tmpmax=0
def dfs(k,add,dif,div,mul,res) :
    global mymin,mymax
    if k==0:
        mymin=min(mymin,res)
        mymax=max(mymax,res)
        return

    idx=len(num)-k
    k-=1
    dfs(k,add-1,dif,div,mul,res+num[idx]) if add>0 else None
    dfs(k,add,dif-1,div,mul,res-num[idx]) if dif>0 else None
    if res<0:
        dfs(k,add,dif,div-1,mul,(res*(-1)//num[idx])*(-1)) if div>0 else None
    else:
        dfs(k,add,dif,div-1,mul,res//num[idx]) if div>0 else None
    dfs(k,add,dif,div,mul-1,res*num[idx]) if mul>0 else None
    k+=1

dfs(totalOper,add,dif,div,mul,num[0])
print(mymax)
print(mymin)