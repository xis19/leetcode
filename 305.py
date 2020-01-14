def numIslands2Slow(m: int, n: int, positions: List[List[int]]) -> List[int]:
    # This is slow
    islands = []
    placed = set()
    result = []
    for position in positions:
        p = (position[0], position[1])

        if p not in placed:
            possible_neighbors = []
            if p[0] != 0: possible_neighbors.append((p[0] - 1, p[1]))
            if p[0] < m - 1: possible_neighbors.append((p[0] + 1, p[1]))
            if p[1] != 0: possible_neighbors.append((p[0], p[1] - 1))
            if p[1] < n - 1: possible_neighbors.append((p[0], p[1] + 1))

            connectable_indices = []
            for index, island in enumerate(islands):
                for neighbor in possible_neighbors:
                    if neighbor in island:
                        connectable_indices.append(index)
                        break

            new_island = {p}
            for index in reversed(connectable_indices):
                new_island = new_island.union(islands[index])
                del islands[index]

            placed.add(p)

            islands.append(new_island)
        result.append(len(islands))

    return result


def numIslands2(m: int, n: int, positions: List[List[int]]) -> List[int]:
    # Faster solution -- use Union Find
    union = dict()

    def find_root(x):
        if union[x] == x:
            return x
        return find_root(union[x])

    def join(x, y):
        x_root = find_root(x)
        y_root = find_root(y)
        union[y_root] = x_root

    num_islands = [0]
    for position in positions:
        pos_t = (position[0], position[1])
        if pos_t in union:
            num_islands.append(num_islands[-1])
            continue

        island_roots = set()
        for dy, dx in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
            if (pos_t[0] + dy, pos_t[1] + dx) in union:
                island_roots.add(find_root((pos_t[0] + dy, pos_t[1] + dx)))

        if not island_roots:
            union[pos_t] = pos_t
            num_islands.append(num_islands[-1] + 1)
        else:
            num_merges = len(island_roots) - 1
            while len(island_roots) > 1:
                i1 = island_roots.pop()
                i2 = island_roots.pop()
                join(i1, i2)
                island_roots.add(i1)
            union[pos_t] = island_roots.pop()
            num_islands.append(num_islands[-1] - num_merges)

    return num_islands[1:]
