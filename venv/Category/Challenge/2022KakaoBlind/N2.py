def solution(cap, n, deliveries, pickups):
    total=0
    while sum(deliveries)+sum(pickups)>0:
        tmp1=0
        tmp2=0
        mem=0
        for i in range(n-1,-1,-1):
            while deliveries[i]!=0 and tmp1<cap:
                tmp1+=1
                deliveries[i]-=1
                mem=max(mem,i)
            while pickups[i]!=0 and tmp2<cap:
                tmp2+=1
                pickups[i]-=1
                mem=max(mem,i)
        total+=mem+1
    return total*2

print(solution(4,5,[1,0,3,1,2],[0,3,0,4,0])) #16
print(solution(2, 7, [1, 0, 2, 0, 1, 0, 2], [0, 2, 0, 1, 0, 2, 0])) #16