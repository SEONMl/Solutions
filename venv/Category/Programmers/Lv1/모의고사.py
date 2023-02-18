def solution(answers):
    t=[[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    N=len(answers)
    person = dict()
    person[1]=person[2]=person[3]=0
    for i in range(N):
        ans=answers[i]
        for j in range(3):
            if ans==t[j][i%len(t[j])]: 
                person[j+1]+=1
    ans=[]
    m=max(person.values())
    for i in range(1,4):
        if person[i]==m:
            ans.append(i)
    return ans

    

solution([1,2,3,4,5])
solution([1,3,2,4,2])
