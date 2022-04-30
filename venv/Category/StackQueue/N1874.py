# 220425
n=int(input())
lst = [int(input()) for i in range(n)]
# 이전 pop - 현재 pop = 1
# 넣을 값(lst[i]) < lst[-1] -> lst.pop() -> "+"
# 반대 면 lst.push() -> "-"

stack = []
last=lst[n-1]
for i in range(1,n):
