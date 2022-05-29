def solution(record):
    dic=dict()
    res=[]
    for rec in record:
        tmp=list(rec.split())
        if len(tmp)==3: # Enter, Change
            gesture,uid,nickname=tmp
            dic[uid] = nickname
        else: # Leave
            gesture,uid=tmp
        res.append((gesture+" "+uid))


    answer = []
    for i in res:
        g,id=i.split()
        if g=="Enter":
            answer.append(dic[id]+"님이 들어왔습니다.")
        elif g=="Leave":
            answer.append(dic[id]+"님이 나갔습니다.")
        else: # change
            continue

    return answer


record=["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
print(solution(record))