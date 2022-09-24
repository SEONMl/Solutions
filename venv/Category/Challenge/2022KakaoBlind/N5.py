def solution(commands):
    ans=[]
    g=[["EMPTY"]*51 for i in range(51)]
    merged=[]
    unmerged=[]
    mem={}
    for cmd in commands:
        tmp=cmd.split()
        if tmp[0]=="UPDATE":
            if len(tmp)==4:
                r,c=int(tmp[1]),int(tmp[2])
                g[r][c]=tmp[3]
                mem.setdefault(tmp[3],[])
                mem[tmp[3]].append((r,c))
            else:
                if tmp[1] in mem.keys():
                    for i,j in mem[tmp[1]]:
                        for m in merged:
                            for p in range(m[1],m[3]):
                                for q in range(m[2],m[4]):
                                    g[p][q]=tmp[2]

        elif tmp[0]=="MERGE":
            r1,c1,r2,c2=int(tmp[1]),int(tmp[2]),int(tmp[3]),int(tmp[4])
            v=g[r1][c1]
            if r1>=r2 and c1>=c2:
                r1,c1,r2,c2=r2,c2,r1,c1
            for i in range(r1,r2+1):
                for j in range(c1,c2+1):
                    g[i][j]=v
            merged.append((v,r1,c1,r2,c2))

        elif tmp[0]=="UNMERGE":
            r,c=int(tmp[1]),int(tmp[2])
            for m in merged:
                if m[1]<=r<=m[3] and m[2]<=c<=m[4]:
                    v=g[r][c]
                for i in range(m[1],m[3]+1):
                    for j in range(m[2],m[4]+1):
                        g[i][j]="EMPTY"
                g[r][c]=v
        elif tmp[0]=="PRINT":
            r,c=int(tmp[1]),int(tmp[2])
            ans.append(g[r][c])
    return ans

print(solution(
["UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"]))