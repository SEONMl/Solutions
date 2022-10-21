def solution(stack1, stack2, stack3):
    st=[stack1,stack2,stack3]
    res=[]
    arr=[[],[],[]]
    while st[0] or st[1] or st[2]:
        for i in range(3):
            if st[i]:
                arr[i]=[st[i][-1],i+1]
            else:
                arr[i]=[0,0]
        tmp=max(arr)
        res.append(tmp)
        for i in range(3):
            if tmp[1]==i+1:
                st[i].pop()
    ans=''
    for i in range(len(res)):
        ans+=str(res[i][1])
    return ans

print(solution([2,7],[4,5],[1]))
print(solution([10, 20, 30], [8], [1]))
print(solution([7], [], [9]))