# 220419 정답 | 복습여부
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))


def binSearch(arr, target, start, end):
    if start > end:
        return None;
    mid = (start + end) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binSearch(arr, target, mid + 1, end)
    else:
        return binSearch(arr, target, start, mid - 1)


A.sort()
for i in B:
    if binSearch(A, i, 0, len(A) - 1) is not None:
        print(1)
    else:
        print(0)
