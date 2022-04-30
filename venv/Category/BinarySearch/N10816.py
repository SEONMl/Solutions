# 220419 정답 | 혼자품? ㄴㄴㄴ dict 생각은 함. 근데 이진탐색으로 풀려고 했음

N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))

# 중복제거 후 dict에 개수 저장?

d={}
for i in A:
    if d.get(i) is None:
        d[i]=1
    else:
        d[i] += 1


for i in B:
    if i in d.keys():
        print(d.get(i), end=" ")
    else:
        print(0, end=" ")
