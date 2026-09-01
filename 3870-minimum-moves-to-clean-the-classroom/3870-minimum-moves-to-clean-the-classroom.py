class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        litters = 0
        start_x = 0
        start_y = 0
        dx      = [0, 1, 0, -1]
        dy      = [1, 0, -1, 0]
        ids     = [[0] * len(classroom[0]) for _ in range(len(classroom))]
        for i, row in enumerate(classroom):
            for j in range(len(row)):
                if row[j] == 'S':
                    start_x = i
                    start_y = j
                elif row[j] == 'L':
                    ids[i][j] = 1 << litters
                    litters += 1
        dq         = collections.deque()
        finished   = 1 << litters
        bestEnergy = [
            [[-1 for _ in range(finished)] for _ in range(len(classroom[0]))]
            for _ in range(len(classroom))
        ]
        dq.append((start_x, start_y, 0, energy, 0))
        bestEnergy[start_x][start_y][0] = energy
        while dq:
            x, y, mask, e, steps = dq.popleft()
            if mask == finished - 1:
                return steps
            if e == 0:
                continue
            for d in range(4):
                nx = x + dx[d]
                ny = y + dy[d]
                if nx < 0 or nx >= len(classroom) or ny < 0 or ny >= len(classroom[0]) or classroom[nx][ny] == 'X':
                    continue;
                ne = energy if classroom[nx][ny] == 'R' else e - 1
                nm = mask | ids[nx][ny]
                if ne > bestEnergy[nx][ny][nm]:
                    bestEnergy[nx][ny][nm] = ne
                    dq.append((nx, ny, nm, ne, steps + 1))
        return -1