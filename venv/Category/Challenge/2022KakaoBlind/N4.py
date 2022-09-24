def solution(numbers):
    ans=[]
    for n in numbers:
        tmp=bin(n)[2:]
        idx=cal(len(tmp))
        tmp="0"*(idx-len(tmp))+tmp
        print(tmp)
        if bs(tmp,0,len(tmp)-1):
            ans.append(1)
        else:
            ans.append(0)
    return ans
def bs(a,s,e):
    mid=(s+e)//2
    while s<e:
        if a[mid]=="1":
            return bs(a,s,mid-1)&bs(a,mid+1,e)
        else:
            return False
    return True
def cal(num):
    for i in range(100):
        if 2**i-1<=num<2**(i+1):
            return 2**(i+1)-1
print(solution([1022]))
print(bin(111))


#실패