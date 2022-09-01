def solution(tickets):
    dit=dict()
    ans=[]
    for i,j in tickets:
        if i in dit:
            dit[i].append(j)
        else:
            dit[i]=[j]

    for i in dit.keys():
        dit[i].sort(reverse=True)
    st=["ICN"]
    while st:
        tmp=st[-1]
        if tmp not in dit or len(dit[tmp])==0:
            ans.append(st.pop())
        else:
            st.append(dit[tmp][-1])
            dit[tmp].pop()
    return ans[::-1]

print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]])) #["ICN", "JFK", "HND", "IAD"]
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]])) #["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]