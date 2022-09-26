import sys;input=sys.stdin.readline
N=int(input())
for _ in range(N):
    tmp=list(map(int,input().rstrip()))
    for i in range(len(tmp)-1,-1,-1):
        if i==0:
            print("BIGGEST")
            break
        if tmp[i]>tmp[i-1]:
            lst=sorted(tmp[i:])
            for idx,n in enumerate(lst):
                if tmp[i-1]<n:
                    tmp[i-1],lst[idx]=lst[idx],tmp[i-1]
                    break
            tmp[i:]=lst
            for i in tmp:
                print(i,end="")
            print()
            break