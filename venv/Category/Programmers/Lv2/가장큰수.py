def solution(numbers):
    strNum=list(map(str,numbers))
    arr=sorted(strNum,key= lambda a: (a*4)[:4],reverse=True)
    if arr[0]=='0':
        return '0'
    print(arr)
    return ''.join(arr)


n=[6,10,2,45,65,99]
n2=[3,30,34,5,9]
print(solution(n))
print(solution(n2))