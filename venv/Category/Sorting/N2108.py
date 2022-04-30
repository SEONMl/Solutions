# 220418
# 아 카운팅 정렬 ㅋ
n=int(input())
num=[]
for _ in range(n):
    num.append(int(input()))
copy=sorted(num)

# 평균
print(round(sum(num)/n))

# 중앙값 n=홀수
print(copy[n//2+1])

# 최빈값 중 두 번째로 작은 값

# 최댓값 최솟값의 차이
print(max(num)-min(num))