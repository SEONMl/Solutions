def solution(n, stations, w):
    cnt,idx=0,0
    i=1
    while i<n+1:
        if idx>=len(stations) or stations[idx]-w>i:
            i+=2*w+1
            cnt+=1
            continue
        else:
            i=stations[idx]+w+1
            idx+=1
    return cnt

print(solution(11,[4,11],1)) # 3
print(solution(16,[9],2))

'''
초기조건 때문에 틀렸음
i=w+1 로 하면 틀림?
def solution(n, stations, w):
    cnt,idx=0,0
    i=1
    while i<n+1:
        if idx<len(stations) and stations[idx]-w<=i<=stations[idx]+w:
            i=stations[idx]+w+1
            idx+=1
            continue
        cnt+=1
        i+=2*w+1
    return cnt
'''