import heapq as hq
def toInt(t):
    return int(t[0])*1000 + int(t[1])*100 +int(t[3])*10 +int(t[4])
def end_time(t):
    time =toInt(t)+10
    if(time%100>=60):
        time-=60
        time+=100
    return time
def solution(book_time):
    book_time.sort()

    heap=[end_time(book_time[0][1])]
    
    for i in range(1,len(book_time)):
        next_start=toInt(book_time[i][0])
        next_end=end_time(book_time[i][1])

        if(heap[0]<=next_start):
            hq.heappop(heap)
        hq.heappush(heap,next_end)
    return len(heap)

solution([["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]])
'''
얜 왜 되냐?
'''