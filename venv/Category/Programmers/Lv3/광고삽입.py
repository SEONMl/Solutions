MAX = 360_000
from heapq import *


def sectotime(sec):
    t = ""
    for i in range(2):
        tmp = str(sec // (60 ** (2 - i)))
        if len(tmp) == 1: t += "0"
        t += tmp
        t += ":"
        sec %= (60 ** (2 - i))
    t += str(sec) if len(str(sec)) == 2 else "0" + str(sec)
    return t

def timetosec(t_str):
    t = list(map(int, t_str.split(":")))
    return t[0] * 60 * 60 + t[1] * 60 + t[2]

def logtotime(log):
    t = []
    log = list(map(str, log.split("-")))
    for l in log:
        t.append(timetosec(l))
    return t

def find(log, play, ad):
    h = []  # 끝난시간
    m = [0] * play
    idx = 0
    for t in range(log[0][0], play - ad + 1):
        while h and h[0] < t:
            heappop(h)
        if idx < len(log) and log[idx][0] == t:
            heappush(h, log[idx][1])
            idx += 1
        m[t] = len(h)

    adTime, maxPop = 0, 0
    for i in range(0, play-ad):
        if maxPop < m[i+ad]:
            adTime = i
            maxPop = max(m[i:i+ad])
    print(sectotime(adTime))

    return adTime


def solution(play_time, adv_time, logs):
    play = timetosec(play_time)
    adv = timetosec(adv_time)
    log = []
    for l in logs:
        log.append(logtotime(l))
    log.sort()
    return sectotime(find(log, play, adv))

# solution("02:03:55","00:14:15",["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"])
solution(	"99:59:59", "25:00:00", ["69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"])