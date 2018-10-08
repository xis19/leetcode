import collections


def numSpecialEquivGroups(A):
    counter = collections.defaultdict(lambda: 0)
    for word in A:
        chars = [[], []]
        for index, ch in enumerate(word):
            chars[index % 2].append(ch)

        counter[(''.join(sorted(chars[0])), ''.join(sorted(chars[1])))] += 1

    return len(counter)
