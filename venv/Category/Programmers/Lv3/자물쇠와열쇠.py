# 효율성 없으면 완전탐색
def solution(key, lock):
    # key lock 크기 같게 만들기
    # 상하좌우 회전 check 해보고 True -> return True
    n=len(lock)
    m=len(key)
    new_lock=[[0]*(n*3) for i in range(n*3)]
    for i in range(n):
        for j in range(n):
            new_lock[i+n][j+n]=lock[i][j]
    print(new_lock)

    for i in range(n*2):
        for j in range(n*2):
            for k in range(4):
                key=rotate(key)
                for x in range(m):
                    for y in range(m):
                        new_lock[i+x][j+y]+=key[x][y]
                if check(new_lock):
                    return True
                for x in range(m):
                    for y in range(m):
                        new_lock[i+x][j+y]-=key[x][y]
    return False


def check(arr):
    n=len(arr)//3
    for i in range(n,n*2):
        for j in range(n,n*2):
            if arr[i][j]==1:
                continue
            return False
    return True

def rotate(arr):
    n=len(arr)
    rot=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            rot[j][n-i-1]=arr[i][j]
    return rot


k=[[0, 0, 0], [1, 0, 0], [0, 1, 1]]
l=[[1, 1, 1], [1, 1, 0], [1, 0, 1]]
print(solution(k,l))
# 열 수 있으면 true 없으면 false
# 열쇠 회전, 이동 가능
# lock ==0 -> key==1 && lock==1 -> key==0
# 상하좌우 이동 -1 +1 ...
# 90도 회전->