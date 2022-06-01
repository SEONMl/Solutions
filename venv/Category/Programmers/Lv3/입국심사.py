def solution(n, times):
    start=min(times) # 최소
    end=max(times)*n # 최대
    answer=0
    while start<=end:
        res=0
        mid=(start+end)//2
        for i in times:
            res+=mid//i
            if res>=n: # 심사관을 모두 거치지 않아도 검사할 수 있으면 탈출한다.
                break

        if res<n:
            start=mid+1
        else:  # res>=n
            answer=mid
            end=mid-1
    return answer

n=6
time=[7,10] # len(time)<=100,000
print(solution(n,time)) # 28
# 어렵당 수학적 센스가 필요하네
# total += (mid/time[i])
# total < n : mid+1
# total > n : mid-1