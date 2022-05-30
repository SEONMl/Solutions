def solution(rows, columns, queries):
    matrix=[[i+j*columns for i in range(1,columns+1)] for j in range(rows)]
    answer = []
    for q in queries:
        y1,x1,y2,x2=q # x==column, y==row
        answer.append(rotate(matrix,x1-1,y1-1,x2-1,y2-1))

    return answer

def rotate(arr,x1,y1,x2,y2): # 1,1,4,3
    tmp=arr[y1][x1]
    mmin=tmp
    for i in range(y1+1,y2+1):
        arr[i-1][x1]=arr[i][x1]
        mmin=min(mmin,arr[i][x1])
    for i in range(x1+1,x2+1):
        arr[y2][i-1]=arr[y2][i]
        mmin = min(mmin, arr[y2][i])
    for i in range(y2-1,y1-1,-1):
        arr[i+1][x2]=arr[i][x2]
        mmin = min(mmin, arr[i][x2])
    for i in range(x2-1,x1-1,-1):
        arr[y1][i+1]=arr[y1][i]
        mmin = min(mmin, arr[y1][i])
    arr[y1][x1+1]=tmp
    return mmin


r1=6
c1=6
q1=[[2,2,5,4],[3,3,6,6],[5,1,6,3]]
q=[[2,2,5,4]]
print(solution(r1,c1,q1))