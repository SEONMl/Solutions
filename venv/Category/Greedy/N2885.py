k=int(input())
i,cnt=0,0
while 1:
    if 2**i<k<=2**(i+1):
        size=2**(i+1)
        print(size,end=" ")
        break
    i+=1
tmp=size
while tmp!=k:
    tmpSize=size//2
    if tmp>k:
        tmp-=tmpSize
    else:
        tmp+=tmpSize
    size=tmpSize
    cnt+=1
print(cnt)