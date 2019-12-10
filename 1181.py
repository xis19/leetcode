import collections

def beforeAndAfterPuzzles(phrases: List[str]) -> List[str]:
    prefix = collections.defaultdict(list)
    postfix = collections.defaultdict(list)

    for index, phrase in enumerate(phrases):
        lsplit = phrase.split(' ', 1)
        if len(lsplit) == 1:
            prefix[phrase].append(('', index))
        else:
            prefix[lsplit[0]].append((lsplit[1], index))

        rsplit = phrase.rsplit(' ', 1)
        if len(rsplit) == 1:
            postfix[phrase].append(('', index))
        else:
            postfix[rsplit[1]].append((rsplit[0], index))


    result = set()
    for key in postfix.keys():
        if key not in prefix:
            continue

        for pre, i_pre in prefix[key]:
            for post, i_post in postfix[key]:
                if i_pre == i_post:
                    continue
                result.add(' '.join((post, key, pre)).strip())

    return sorted(list(result))
