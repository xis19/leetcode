def wordPattern(pattern: str, string: str) -> bool:
    mapper = {}
    rev_mapper = {}

    split = string.split()
    if len(split) != len(pattern):
        return False

    for p, s in zip(list(pattern), split):
        if mapper.get(p) and mapper[p] != s:
            return False
        if rev_mapper.get(s) and rev_mapper[s] != p:
            return False
        mapper[p] = s
        rev_mapper[s] = p

    return True
