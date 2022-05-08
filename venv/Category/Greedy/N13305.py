# 220508
import sys
n = int(input())
d = list(map(int, input().split()))  # distance | n-1
p = list(map(int, input().split()))  # price | n
# cost= d[i]*p[i]
# mymin 싼 기름값
cost=0
mymin=sys.maxsize
for i in range(n-1):
    mymin=min(mymin,p[i])
    cost+=mymin*d[i]
print(cost)