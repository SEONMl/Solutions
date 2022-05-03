n,m=map(int,input().split())

def dfs(start,arr):
    if len(arr)==m:
        print(' '.join(map(str, arr)))
        return
    for i in range(start, n+1):
        arr.append(i)
        dfs(i,arr)
        arr.pop()
dfs(1,[])