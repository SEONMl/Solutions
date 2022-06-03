arr=[int(input()) for i in range(10)]
res,i=0,0
while res<100 and i<10:
    prev=res
    res+=arr[i]
    i+=1
if abs(100-prev)<abs(100-res):
    res=prev
print(res)