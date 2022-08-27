def solution(n, lost, reserve):
    cnt=n-len(lost)
    visit=[0]*len(reserve)
    for i in lost:
        for j,num in enumerate(reserve):
            if num-1<=i<=num+1 and not visit[j]:
                visit[j]=1
                cnt+=1
                break
    return cnt

print(solution(5,[2,4],[1,3,5])) # 5
print(solution(5,[2,4],[3])) # 4