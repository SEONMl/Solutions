def solution(nums):
    a=len(set(nums))
    return a if a<=len(nums)/2 else len(nums)/2
# N개 배열 -> set화
# N/2 개 선택
# set>N/2 print N/2 else len(set)