replaced=[["C#","H"],["D#","I"],["F#","J"],["G#","K"],["A#","L"]]

def replaceSharp(s):
    for each in replaced:
        s=s.replace(each[0],each[1])
    return s

def timetomin(t):
    h,m=t.split(":")
    return int(h)*60+int(m)  
  
def getDiff(s,e):
    return timetomin(e)-timetomin(s)

def solution(m, musicinfos):
    answer = []
    m=replaceSharp(m)
    for idx,i in enumerate(musicinfos):
        s,e,title,melody=i.split(",")
        diff=getDiff(s,e)
        melody=replaceSharp(melody)
        
        for each in m:
            if each not in set(melody):
                continue
                
        melody=melody*(diff//len(melody))+melody[0:diff%len(melody)]
        if m in melody:
            answer.append([diff, idx, title])
        
    if not answer:
        return "(None)"
    answer.sort(key=lambda a:a[0],reverse=True)
    return answer[0][2]