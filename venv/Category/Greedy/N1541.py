# 220424 정답

s = input()
stack = []
tmp = []
stack.append("(")
for c in s:
    if not tmp and c == "0":
        continue
    if c == "-":
        stack.append(''.join(tmp))
        stack.append(")-(")
        tmp = []

    elif c == "+":
        stack.append(''.join(tmp))
        stack.append("+")
        tmp = []

    else:
        tmp.append(c)

stack.append(''.join(tmp))
stack.append(")")
print(eval(''.join(stack)))
