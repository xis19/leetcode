import collections
import string

def smallestEquivalentString(A: str, B: str, S: str) -> str:
    union_find = {}

    def find_root(a):
        while union_find[a] != a:
            a = union_find[a]
        return a

    def merge(a, b):
        a_root = find_root(a)
        b_root = find_root(b)
        union_find[b_root] = a_root

    for a, b in zip(A, B):
        if a not in union_find:
            union_find[a] = a
        if b not in union_find:
            union_find[b] = b
        merge(a, b)

    same_root = collections.defaultdict(set)
    for k in union_find:
        same_root[find_root(k)].add(k)

    smallest_dict = {}
    for s in string.ascii_lowercase:
        smallest_dict[s] = s
    for v in same_root.values():
        m = min(v)
        for k in v:
            smallest_dict[k] = m

    return ''.join(smallest_dict[s] for s in S)
