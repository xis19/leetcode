def maximumMinimumPath(A: List[List[int]]) -> int:
    # We could search for all possible paths
    # but a more affordable solution is to sort the cells by score, and pop up
    # the highest scored cells until the beginning and ending path
    M = len(A)
    N = len(A[0])

    score_pad = []
    for y, r in enumerate(A):
        for x, s in enumerate(r):
            score_pad.append((s, y, x))

    score_pad.sort()

    current_score = min(A[0][0], A[M - 1][N - 1])
    union = {(0, 0): (0, 0), (M - 1, N - 1): (M - 1, N - 1)}

    def find_root(x):
        while union[x] != x:
            x = union[x]
        return x

    def join(x, y):
        xroot = find_root(x)
        yroot = find_root(y)
        union[yroot] = xroot

    while find_root((0, 0)) != find_root((M - 1, N - 1)):
        score = score_pad[-1][0]
        while len(score_pad) > 1 and score_pad[-1][0] == score:
            _s, _y, _x = score_pad[-1]
            score_pad.pop()

            u = set()
            for dy, dx in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                y = _y + dy
                x = _x + dx
                if y < 0 or y >= M or x < 0 or x >= N:
                    continue
                if (y, x) in union:
                    u.add(find_root((y, x)))

            if len(u) == 0:
                union[(_y, _x)] = (_y, _x)
            else:
                while len(u) > 1:
                    i = u.pop()
                    j = u.pop()
                    join(i, j)
                    u.add(i)
                union[(_y, _x)] = u.pop()

        current_score = min(current_score, score)

    return current_score
