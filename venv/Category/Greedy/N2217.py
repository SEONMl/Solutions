n=int(input())
w=[int(input()) for i in range(n)]
w.sort(reverse=True)
res=[]
for i in range(n):
    res.append(w[i]*(i+1))
print(max(res))