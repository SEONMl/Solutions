# 220424 정답
n=int(input())
p=list(map(int, input().split()))

p.sort()
cum=[0] * n
cum[0]=p[0]

for i in range(1,n):
    cum[i]=cum[i-1]+p[i]
print(sum(cum))
