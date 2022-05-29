# LinkedList 구현
N=10**9
class Node:
    survived=True

    def __init__(self,p,n):
        self.prev=p if p>=0 else None
        self.next=n if n<N else None

def solution(n0, k, cmd):
    global N
    N=n0
    recent=[]
    cur=k
    linkedList={i:Node(i-1,i+1) for i in range(n0)}
    print(linkedList)
    for c in cmd:
        if c=="C": # 삭제
            p,n=linkedList[cur].prev ,linkedList[cur].next
            linkedList[cur].survived=False
            recent.append(cur)

            if p is not None: linkedList[p].next=linkedList[cur].next
            if n is not None: linkedList[n].prev=linkedList[cur].prev

            if linkedList[cur].next is None:
                cur=linkedList[cur].prev
            else:
                cur=linkedList[cur].next

        elif c=="Z": # 복구
            tmp=recent.pop()
            linkedList[tmp].survived=True
            p,n=linkedList[tmp].prev, linkedList[tmp].next
            if p is not None: linkedList[p].next=tmp
            if n is not None: linkedList[n].prev=tmp

        else: # 탐색
            s,num=c.split()
            num=int(num)
            if s=="U":
                for _ in range(num):
                    cur=linkedList[cur].prev
            else:
                for _ in range(num):
                    cur=linkedList[cur].next
    return ''.join(["O" if linkedList[p].survived else "X" for p in range(n0)])


def solution22(n, k, command):
    global N
    N = n
    table = {i: Node(i - 1, i + 1) for i in range(n)}
    current = k
    removed = []
    print(table)
    for cmd in command:
        if cmd == "C":  # 삭제
            table[current].survived = False
            removed.append(current)

            prev, next = table[current].prev, table[current].next
            # 앞 노드의 next를 뒷 노드에 연결
            if prev is not None: table[prev].next = table[current].next
            # 뒷 노드의 prev를 앞 노드에 연결
            if next is not None: table[next].prev = table[current].prev

            # 노드 제거
            if table[current].next is None:  # 다음 노드가 없음
                current = table[current].prev
            else:  # 다음 노드가 있음
                current = table[current].next

        elif cmd == "Z": # 실행 취소
            recovered = removed.pop()
            table[recovered].survived = True

            # 앞 노드의 next를 자신으로 연결
            prev, next = table[recovered].prev, table[recovered].next
            if prev is not None: table[prev].next = recovered
            # 뒤 노드의 prev를 자신으로 연결
            if next is not None: table[next].prev = recovered


        else:
            c, amount = cmd.split()
            if c == "U":
                # 위로
                for _ in range(int(amount)):
                    current = table[current].prev

            elif c == "D":
                # 아래로
                for _ in range(int(amount)):
                    current = table[current].next

    return ''.join(["O" if table[i].survived else "X" for i in range(n)])

n=8 # 0~n-1
k=2
c1=["D 2","C","U 3","C","D 4","C","U 2","Z","Z"] # "OOOOXOOO"
c2=["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"] # "OOXOXOOO"
print(solution22(n,k,c1))
print(solution(n,k,c1))