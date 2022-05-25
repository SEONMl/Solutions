def solution(numbers):
    origin=set([1,2,3,4,5,6,7,8,9,0])
    for i in numbers:
        origin.remove(i)
    sum=0
    for iter in origin:
        sum+=iter
    return sum
#wow..
def sol(numbers):
    return 45-sum(numbers)
def sol2(numbers):
    return sum(set(range(10))-set(numbers))