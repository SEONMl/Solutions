import sys
input=sys.stdin.readline
target=int(input())
ans=abs(100 - target) # ++ or -- 로 이동할 경우 -> 최댓값
M=int(input())
if M:
    broken=list(map(str,input().split()))
else:  # 예외처리
    broken=set()
for num in range(1000001):
    for N in str(num):
        if N in broken:  # 해당 숫자가 번호를 눌러서 만들 수 없는 경우엔 스탑
            break
    else:  # 번호를 눌러서 만들 수 있는 경우엔
        ans=min(ans,len(str(num))+abs(num-target))
print(ans)

# OMG... 문법 이렇게가 가능해...?