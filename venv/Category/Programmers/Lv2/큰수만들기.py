def sol(num,k):
    ans=[]
    for i,n in enumerate(num):
        while len(ans)>0 and ans[-1]<n and k>0:
            ans.pop()
            k-=1
        if k==0:
            ans+=list(num[i:])
            break
        ans.append(n)
    ans=ans[:-k] if k>0 else ans
    return ''.join(ans)
