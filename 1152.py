import collections

def mostVisitedPattern(username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
    data = list(zip(username, timestamp, website))
    data.sort(key=lambda i: i[1])

    usermap = collections.defaultdict(list)
    for un, ts, ws in data:
        usermap[un].append(ws)

    tuple_counter = collections.defaultdict(lambda: 0)

    for _, visits in usermap.items():
        visit_tuple = set()
        l = len(visits)

        for i in range(0, l):
            for j in range(i + 1, l):
                for k in range(j + 1, l):
                    visit_tuple.add((visits[i], visits[j], visits[k]))

        for i in visit_tuple:
            tuple_counter[i] += 1

    max_count = max(tuple_counter.values())
    result = None
    for t, c in tuple_counter.items():
        if c == max_count:
            result = t if result is None else min(result, t)

    return result
