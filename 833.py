def findReplaceString(S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
    res = []
    index = 0
    while index < len(S):
        character = S[index]

        if index not in indexes:
            res.append(character)
            index += 1
            continue

        i_index = indexes.index(index)
        if not S[index:].startswith(sources[i_index]):
            res.append(character)
            index += 1
            continue

        index += len(sources[i_index])
        res.append(targets[i_index])

    return ''.join(res)
