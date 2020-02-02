import copy

def minFlips(mat: List[List[int]]) -> int:
    M = len(mat)
    N = len(mat[0])

    def is_same(mat1, mat2):
        for y in range(0, M):
            for x in range(0, N):
                if mat1[y][x] != mat2[y][x]:
                    return False
        return True

    def flip(matrix, y, x):
        for cy, cx in [[y, x], [y - 1, x], [y + 1, x], [y, x - 1], [y, x + 1]]:
            if cy < 0 or cx < 0 or cy >= M or cx >= N:
                continue
            matrix[cy][cx] = 1 if matrix[cy][cx] == 0 else 0

    def all_zero(matrix):
        return not any(any(r) for r in matrix)

    queue = [(mat, 0)]
    visited = [mat]
    while len(queue):
        m, step = queue[0]
        queue = queue[1:]

        if all_zero(m):
            return step

        for y in range(0, M):
            for x in range(0, N):
                new_mat = copy.deepcopy(m)
                flip(new_mat, y, x)
                if any(is_same(new_mat, old) for old in visited):
                    continue
                visited.append(new_mat)
                queue.append((new_mat, step + 1))

    return -1
