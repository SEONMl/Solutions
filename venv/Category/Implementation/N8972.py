# ^^... kraj 인데 krag 로 제출해서 계속 틀림 ^^^^~~~~~~~
import sys;input=sys.stdin.readline
R,C=map(int,input().split())
dr=[0,1,1,1,0,0,0,-1,-1,-1]
dc=[0,-1,0,1,-1,0,1,-1,0,1]
ardu=[]
for i in range(R):
    temp=input().rstrip()
    for j,k in enumerate(temp):
        if k=="I":
            I=(i,j)
        if k=="R":
            ardu.append((i,j))
S=input().rstrip()

def check(i,a):
    if I in ardu:
        print("kraj",idx+1)
        exit(0)

for idx,val in enumerate(S):
    val=int(val)
    I=(I[0]+dr[val],I[1]+dc[val])
    check(I,ardu)
    copied=set()
    crush=set()

    for r,c in ardu:
        mem=[5,9999]
        for _i in range(1,10):
            nr,nc=(r+dr[_i],c+dc[_i])
            if 0<=nr<R and 0<=nc<C:
                tmp=abs(I[0]-nr)+abs(I[1]-nc)
                if tmp<mem[1]:
                    mem=[_i,tmp]

        ans=(r+dr[mem[0]],c+dc[mem[0]])
        if I==ans:
            print("kraj",idx+1)
            exit(0)
        if ans in copied:
            crush.add(ans)
        copied.add(ans)
    ardu=list(copied-crush)

g=[["."]*C for i in range(R)]
for x,y in ardu:
    g[x][y]="R"
g[I[0]][I[1]]="I"
for i in range(R):
    print(''.join(g[i]))