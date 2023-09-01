MAX=360_000
from heapq import *

def sectotime(sec):
    t=""
    for i in range(2):
        t+=str(sec//(60**(2-i)))
        t+=":"
        sec%=(60**(2-i))
    t+=str(sec)
    return t
def timetosec(t_str):
    t=list(map(int,t_str.split(":")))
    return t[0]*60*60+t[1]*60+t[2]
def logtotime(log):
    t=[]
    log=list(map(str,log.split("-")))
    for l in log:
        t.append(timetosec(l))
    return t

def find(log,play,ad):
    h=[] #끝난시간
    m=[0,MAX]
    idx=0
    print(log)
    for t in range(ad,play):
        while h and h[0]<t:
            print(h)
            heappop(h)
        while idx<len(log) and log[idx][0]<=t:
            heappush(h,log[idx][1])
            idx+=1
        if m[0]<len(h):
            m[0]=len(h)
            m[1]=t-ad
        
    print(m)
    return m[1]

def solution(play_time, adv_time, logs):
    play=timetosec(play_time)
    adv=timetosec(adv_time)
    log=[]
    for l in logs:
        log.append(logtotime(l))
    log.sort()
    return sectotime(find(log, play, adv))

solution("02:03:55","00:14:15",["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"])