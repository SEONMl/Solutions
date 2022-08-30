import heapq as h
def solution(operations):
    ans=[0,0]
    maxh=[]
    minh=[]
    for oper in operations:
        cmd,num=oper.split()
        num=int(num)
        if cmd=="I":
            h.heappush(maxh,(-num,num))
            h.heappush(minh,num)
        elif cmd=="D" and num==1 and maxh:
            h.heappop(maxh)
            minh.pop()
        elif cmd=="D" and num==-1 and minh:
            h.heappop(minh)
            maxh.pop()
    if minh and ans[1]>minh[0]:
        ans[1]=minh[0]
        ans[0]=maxh[0][1]
    if maxh and ans[0]<maxh[0][1]:
        ans[0]=maxh[0][1]
        ans[1]=minh[0]
    return ans

print(solution(["I 16", "I -5643", "D -1", "D 1", "I 123"]))
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))
#드릅다 드르워