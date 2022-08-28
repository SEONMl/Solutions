x,y,w,s=map(int,input().split())
time1=(x+y)*w
if (x+y)%2==0:
    time2=max(x,y)*s
else:
    time2=(max(x,y)-1)*s+w
time3=abs(x-y)*w+min(x,y)*s
print(min(time1,time2,time3))