import sys
input=sys.stdin.readline
V,E=map(int,input().split())
INF=sys.maxsize
distance=[INF]*(V+1)
g=[]
for i in range(E):
    s,e,w=map(int,input().split())
    g.append([s,e,w])

def bellman_ford(start):
    distance[start]=0
    for i in range(1,V+1):
        # 매 반복마다 '모든 간선'을 확인한다.
        for j in range(E):
            cur_node=g[j][0]
            next_node=g[j][1]
            cost=g[j][2]
            if distance[cur_node]!=INF and distance[next_node]>distance[cur_node]+cost:
                distance[next_node]=distance[cur_node]+cost
                # V번째 라운드에서도 값이 갱신된다면 음수사이클이 존재
                if i==V:
                    return True
    return False

nag_cycle=bellman_ford(1)
if nag_cycle:
    print(-1)
else:
    for i in range(2, V+1):
        if distance[i]==INF:
            print(-1)
        else:
            print(distance[i])