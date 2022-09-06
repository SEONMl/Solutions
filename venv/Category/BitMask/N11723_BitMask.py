import sys;input=sys.stdin.readline
N=int(input())
S=0
for _ in range(N):
    tmp=input().rstrip().split()
    if len(tmp)==1:
        cmd=tmp[0]
    else:
        cmd,n=tmp[0],int(tmp[1])-1
    if cmd=="add":
        S|=(1<<n)
    elif cmd=="remove":
        S&=~(1<<n)
    elif cmd=="check":
        if S&(1<<n):
            print(1)
        else:
            print(0)
    elif cmd=="toggle":
        S^=(1<<n)
    elif cmd=="all":
        S=(1<<20)-1
    elif cmd=="empty":
        S=0

"""
원소추가(OR): A |= (1 << k)
원소삭제(AND): A &= ~(1 << k)
원소확인(AND): if(A & (1 << k)) 
토글(XOR): A ^= (1 << k)

최소 원소 찾기: int first = A & (-A)
최소 원소 지우기: A &= (A - 1)

집합 크기 구하기:
int bitCount(int A){ 
    if(A == 0)
        return 0
    return A%2 + bitCount(A / 2)
}
"""