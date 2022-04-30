import sys

n = int(input())
lst = [list(map(int, " ".join(sys.stdin.readline()).split())) for i in range(n)]

stack = []


def quadTree(arr, x, y, k):
    val = arr[x][y]
    dx = x // k
    dy = y // k
    stack.append("(")
    for i in range(x, x + k):
        for j in range(y, y + k):
            if(arr[i][j] != val):
                quadTree(arr, x, y, k//2)
                quadTree(arr, x, y+dy, k//2)
                quadTree(arr, x+dx, y, k//2)
                quadTree(arr, x+dx, y+dy, k//2)
                return
        stack.append(val)
    stack.append(")")

quadTree(lst, 0,0,n)
for i in stack:
    print(i,end="")