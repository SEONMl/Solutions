# 220427 정답 | N의 범위가 작을 땐 만들어 놓는 게 빠를 수 있다.
n=int(input())

seq=[1,1,1,2,2]
for j in range(5, 100):
    seq.append(seq[j - 1] + seq[j - 5])

for i in range(n):
    N=int(input())
    print(seq[N-1])