def flipgame(fronts: List[int], backs: List[int]) -> int:
    both_side_same = set()

    # First, if any card that has same value from both side, the value cannot
    # be used
    for f, b in zip(fronts, backs):
        if f == b:
            both_side_same.add(f)

    min_value = 3000    # max value is 2000
    # Then we find the minimum value not in the set, and flip it. We could
    # always let the same value appear on the other side by flipping
    for f, b in zip(fronts, backs):
        if f != b:
            if f not in both_side_same:
                min_value = min(min_value, f)
            if b not in both_side_same:
                min_value = min(min_value, b)

    return min_value if min_value != 3000 else 0
