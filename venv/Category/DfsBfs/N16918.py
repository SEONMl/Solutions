import sys
from collections import deque
input=sys.stdin.readline
r,c,n=map(int,input().split())
g=[' '.join(input()).split() for i in range(r)]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
def loc_bomb():
    for i in range(r):
        for j in range(c):
            if g[i][j]=='O':
                bomb.append((i,j))
def full_bomb():
    for i in range(r):
        for j in range(c):
            if g[i][j]!="O":
                g[i][j]="O"
def bombs():
    while bomb:
        a, b = bomb.popleft()
        g[a][b] = "."

        for i in range(4):
            x=a+dx[i]
            y=b+dy[i]
            if 0<=x<r and 0<=y<c:
                if g[x][y]=="O":
                    g[x][y]="."
n-=1
while n:
    bomb=deque()
    loc_bomb()
    full_bomb()

    n-=1
    if n==0:
        break
    bombs()
    n-=1

for i in g:
    print("".join(i))