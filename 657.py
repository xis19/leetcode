import collections

def judgeCircle(moves: str) -> bool:
    cc = collections.defaultdict(lambda: 0)
    for ch in moves:
        cc[ch] += 1
    return cc['U'] == cc['D'] and cc['L'] == cc['R']
