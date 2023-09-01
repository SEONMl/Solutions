def solution(S):
    N=len(S)
    counting=[0,0,0] # A,B,N 개수
    for i in S:
        if i=='A': counting[0]+=1
        elif i=='B': counting[1]+=1
        elif i=='N': counting[2]+=1
    counting[0]//=3
    counting[2]//=2
    return min(counting)
print(solution("NANANAAAANBANANNANANAAAAANANANABBBBBBBBNANANNANANANANANNNANANANNANA"))