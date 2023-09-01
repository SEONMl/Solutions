import sys;input=sys.stdin.readline

n=int(input())
pairs=[list(map(int,input().split())) for i in range(n)]
pairs.append(pairs[0])

x=y=0
for i in range(1,n+1):
    x+=pairs[i][1]*pairs[i-1][0]
    y+=pairs[i][0]*pairs[i-1][1]

print(round(abs((x-y))/2, 1))