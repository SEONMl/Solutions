def solution(id_list, report, k):
    id=dict() # {str:int}
    reported=dict() #{int:int}
    arr=[[] for i in range(len(id_list))]
    answer=[0]*len(id_list)
    for i in range(len(id_list)):
        id[id_list[i]]=i
        reported[i]=0
    report=set(report)
    for i in report:
        p,q=i.split()
        reported[id[q]]+=1
        arr[id[p]].append(id[q])

    for i,j in reported.items():
        if j>=k:
            for n in range(len(arr)):
                for m in arr[n]:
                    if m==i:
                        answer[n]+=1
    return answer

id=["muzi", "frodo", "apeach", "neo"]
id2=[]
report=["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k=2
print(solution(id,report,k))
# 다른 이용자에게 k번 신고받으면 신고 처리
# [2,1,1,0] : 신고처리결과