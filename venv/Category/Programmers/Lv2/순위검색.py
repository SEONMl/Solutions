from bisect import bisect_left
candi=dict()
def splitQuery(queries):
    answer=[]
    for query in queries:
        q = query.split()
        score = int(q[-1])

        condition = [q[0], q[2], q[4], q[6]]
        key = ''.join(condition)

        if key in candi:
            scores = candi[key]
            if scores:
                idx = bisect_left(scores, score)
                answer.append(len(scores)-idx)
        else:
            answer.append(0)
    return answer

def splitInfo(info):
    for i in info:
        person = i.split()
        score=int(person[-1])
        for j in range(2): # 언어
            tmp=[]
            tmp.append(person[0] if j else "-")
            for k in range(2): # 직군
                tmp.append(person[1] if k else "-")
                for l in range(2): # 경력
                    tmp.append(person[2] if l else "-")
                    for m in range(2): # 소울푸드
                        tmp.append(person[3] if m else "-")

                        key = ''.join(tmp)
                        if key in candi:
                            candi[key].append(score)
                        else:
                            candi[key] = [score]

                        tmp.pop()
                    tmp.pop()
                tmp.pop()
            tmp.pop()

def solution(info, queries):
    splitInfo(info)
    for i in candi:
        candi[i].sort()
    return splitQuery(queries)
