while 1:
    s=input()
    if s==".":
        exit(0)
    stk=[]
    for c in s:
        if c=="(" or c=="[":
            tmp=")" if c=="(" else "]"
            stk.append(tmp)
            continue
        if c==")" or c=="]":
            if (stk and c!=stk[-1]) or (not stk):
                stk.append(c)
                break
            stk.pop()
    print("yes") if not stk else print("no")