moum=['A','E','I','O','U']
answer=0
cnt=0
def dfs(target,cur):
    global answer,cnt
    if(len(cur)==6):
         return
    if cur==target:
        answer=cnt
        return 
    cnt+=1

    for i in moum:
        dfs(target,cur+i)
        
        
def solution(word):
    global answer
    answer=0
    dfs(word,"")
    return answer