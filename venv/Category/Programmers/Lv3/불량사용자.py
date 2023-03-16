def check(user, ban):
    if len(user)!=len(ban): 
        return False
    for i in range(len(user)):
        if user[i]!=ban[i]:
            if ban[i]=="*":
                continue
            return False
    return True
    
combi=[]
def dfs(idx,N, arr, cur):
    if idx==N:
        copied=cur.copy()
        copied.sort()
        if copied not in combi:
            combi.append(copied)
        return
    
    for i in arr[idx]:
        if i in cur: continue
        cur.append(i)
        dfs(idx+1,N,arr,cur)
        cur.pop()
        
def solution(user_id, banned_id):
    BAN=len(banned_id)
    ban_arr=[[] for i in range(BAN)]
    
    for idx,ban in enumerate(banned_id):
        for user in user_id:
            if check(user,ban):
                ban_arr[idx].append(user)
                
    dfs(0,BAN,ban_arr,[])
    print(combi)
    return len(combi)
