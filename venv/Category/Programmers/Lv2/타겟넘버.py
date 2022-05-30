def solution(numbers, target):
    sup=[0]
    for i in numbers:
        tmp=[]
        for j in sup:
            tmp.append(j+i)
            tmp.append(j-i)
        sup=tmp
    return sup.count(target)


n1=[4, 1, 2, 1] # 2
n2=[1,1,1,1,1] # 5
t1=4
t2=3
print(solution(n1,t1))
# 숫자 순서 바꾸지 않고 더하거나 빼서 타겟넘버 만드는 방법의 수
# numbers <= 20 2^20