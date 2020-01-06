def pourWater(heights: List[int], V: int, K: int) -> List[int]:
    for _ in range(V):
        heights[K] += 1

        # NOTE: we need to carry the poured droplet to the lowest level, while
        # not passing the peaks
        move = False
        carry_index = K
        for i in range(K - 1, -1, -1):
            if heights[i] < heights[carry_index] - 1:
                heights[carry_index] -= 1
                heights[i] += 1
                carry_index = i
                move = True
            elif heights[i] >= heights[carry_index]:
                break
        if move:
            continue

        for i in range(K + 1, len(heights)):
            if heights[i] < heights[carry_index] - 1:
                heights[carry_index] -= 1
                heights[i] += 1
                carry_index = i
            elif heights[i] >= heights[carry_index]:
                break

    return heights
