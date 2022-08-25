def solution(participant, completion):
    dic=dict()
    for i in participant:
        dic[i]=dic.setdefault(i,0)+1
    for i in completion:
        dic[i]-=1
    for i,j in dic.items():
        if j==1:
            return i
q=solution(["marina", "josipa", "nikola", "vinko", "filipa"],["josipa", "filipa", "marina", "nikola"])
print(q)