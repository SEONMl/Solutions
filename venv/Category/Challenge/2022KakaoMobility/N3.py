import datetime as dt
def solution(start, times):
    flag=1
    formattedStartDay=formatToDatetime(start)

    prevDay=formattedStartDay
    for time in times:
        dd,hh,mm,ss=map(int,time.split(":"))
        nextDay=prevDay+dt.timedelta(days=dd,hours=hh,minutes=mm,seconds=ss)
        if(calculateDays(prevDay,nextDay) > 2):
            flag=0
        prevDay=nextDay

    duration=calculateDays(formattedStartDay, prevDay)
    return [flag, duration]

def calculateDays(start, end):
    year=end.year-start.year
    month=end.month-start.month
    day=end.day-start.day

    day+=360*year
    day+=30*month

    return day+1

def formatToDatetime(string):
    lst=list(map(int,string.split(":")))
    return dt.datetime(lst[0],lst[1],lst[2],lst[3],lst[4],lst[5])

print(solution("2021:04:12:16:08:35", ["01:06:30:00", "00:01:12:00"]))
print(solution(
"2021:04:12:16:08:35", ["01:06:30:00", "01:04:12:00"]))