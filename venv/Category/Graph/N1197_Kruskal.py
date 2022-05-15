# 최소신장트리 - 전체 요소들을 연결
# root를 저장하는 Vroot 배열 생성(root는 연결요소 중 가장 작은 값)
# 간선들을 정렬
# 간선이 잇는 두 정점의 root를 찾는다
# 다르다면 하나의 root를 바꾸어 연결 시켜준다.
# 간선이 적으면 Kruskal | 시간 388ms
import sys
input=sys.stdin.readline
V,E=map(int,input().split())
vRoot=[i for i in range(V+1)]
eList=[]
for _ in range(E):
    eList.append(list(map(int,input().split())))
eList.sort(key=lambda x:x[2]) # 가중치 기준으로 정렬

def find(x):
    if x!=vRoot[x]:
        vRoot[x]=find(vRoot[x])
    return vRoot[x]
res=0
for start, end, weight in eList:
    sRoot=find(start)
    eRoot=find(end)
    if sRoot!=eRoot:
        if sRoot>eRoot:
            vRoot[sRoot]=eRoot
        else:
            vRoot[eRoot]=sRoot
        res+=weight
print(res)