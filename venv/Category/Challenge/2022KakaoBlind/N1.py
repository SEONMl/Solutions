from datetime import datetime,timedelta
def solution(today, terms, privacies):
    ans=[]
    dic={}
    t=list(map(int,today.split(".")))
    for i in terms:
        tmp=i.split()
        dic[tmp[0]]=int(tmp[1])
    for idx,p in enumerate(privacies):
        i,j=p.split()
        formed=list(map(int,i.split('.')))
        if check(t,dic[j],formed):
            ans.append(idx+1)
    return ans
def check(tod,mon,pri):
    pri[1]+=mon
    while pri[1]>12:
        pri[0]+=1
        pri[1]-=12
    return True if pri<=tod else False

print(solution(
"2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]))
print(solution(
"2020.01.01", ["Z 3", "D 5"], ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]))