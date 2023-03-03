'''
3<=n<=15
- _ .(끝, 연속 사용 불가)
lower, 문자 제거, 마침표 중복 제거, 처음끝 마침표 제거, 빈문자열 = a, 글자수 제한, 마침표는 제거, 마지막문자 3될때까지
'''
MIN=3
MAX=15
def deleteLastOnjum(id):
    if len(id)>0 and id[-1]==".": 
        id=id[0:len(id)-1]
    return id
def deleteWord(s):
    id=""
    for c in s:
        if c in ("-","_",".") or 'a'<=c<='z' or '0'<=c<='9':
            if(len(id)>0 and id[-1]=="." and c=="."): continue
            if len(id)==0 and c==".": continue
            id+=c
    id=deleteLastOnjum(id)
    if len(id)==0:
        id="a"
    return id
def limit(id):
    if len(id)<MIN:
        while len(id)<3:
            id+=id[-1]
    elif len(id)>MAX:
        id=id[0:15]
        id=deleteLastOnjum(id)
    return id
def solution(new_id):
    answer=deleteWord(new_id.lower())
    answer=limit(answer)
    return answer