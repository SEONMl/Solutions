n=1000-int(input())
a=[500,100,50,10,5,1]
cnt,idx=0,0
while idx<len(a):
    cnt+=n//a[idx]
    n%=a[idx]
    idx+=1
print(cnt)