origin = [['EMPTY'] * 51 for i in range(51)]
mapping = [[[i, j] for j in range(51)] for i in range(51)]


def merge(pos1, pos2):
    x, y = pos1;
    r, c = pos2
    x1, y1 = mapping[x][y]
    x2, y2 = mapping[r][c]

    if origin[x1][y1] == "EMPTY":
        origin[x1][y1] = origin[x2][y2]

    for i in range(1, 51):
        for j in range(1, 51):
            if mapping[i][j] == [x2, y2]:
                mapping[i][j] = [x1, y1]


def unmerge(pos):
    x, y = mapping[pos[0]][pos[1]]
    value = origin[x][y]
    for i in range(1, 51):
        for j in range(1, 51):
            if mapping[i][j] == [x,y]:
                mapping[i][j] = [i, j]
                origin[i][j] = "EMPTY"
    origin[pos[0]][pos[1]] = value


def update(r, c, v):
    mapped = mapping[r][c]
    origin[mapped[0]][mapped[1]] = v


def updateAll(v1, v2):
    for i in range(1, 51):
        for j in range(1, 51):
            if origin[i][j] == v1:
                origin[i][j] = v2


def solution(commands):
    answer = []

    for command in commands:
        cmd = command.split()
        if cmd[0] == "UPDATE":
            if len(cmd) == 4:
                r, c, v = int(cmd[1]), int(cmd[2]), cmd[3]
                # map->update
                update(r, c, v)
            else:
                v1, v2 = cmd[1], cmd[2]
                # 완탐
                updateAll(v1, v2)
        elif cmd[0] == "MERGE":
            r1, c1, r2, c2 = int(cmd[1]), int(cmd[2]), int(cmd[3]), int(cmd[4])
            merge([r1, c1], [r2, c2])
        elif cmd[0] == "UNMERGE":
            r, c = int(cmd[1]), int(cmd[2])
            # mapping 완탐
            unmerge([r, c])
        elif cmd[0] == "PRINT":
            r, c = int(cmd[1]), int(cmd[2])
            mapped = mapping[r][c]
            answer.append(origin[mapped[0]][mapped[1]])

    return answer