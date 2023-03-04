from itertools import combinations

def alreadyCandidate(answer, combi):
    for ans in answer:
        cnt=0
        for a in ans:
            if a in combi:
                cnt+=1
        if cnt==len(ans):
            return True
    return False

def isCandiKey(rel,combi):
    ROW=len(rel)
    tups=set()
    
    for p in range(ROW):
        tmp=[]
        for q in combi:
            tmp.append(rel[p][q])
        tups.add(tuple(tmp))
        
    if len(tups)==ROW:
        return True
    return False

def solution(rel):
    answer = []
    COL=len(rel[0])
    cols=[i for i in range(COL)]
    
    for i in range(1,COL+1):
        for combi in combinations(cols,i):
            if isCandiKey(rel, combi) and not alreadyCandidate(answer,combi):
                answer.append(combi)
        
    print(answer)
    return len(answer)

print((1,2) in (1,2,3))
#solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]])
solution([['a',1,'aaa','c','ng'],
          ['b',1,'bbb','c', 'g'],
          ['c',1,'aaa','d','ng'],
          ['d',2,'bbb','d','ng']])

