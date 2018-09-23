import collections


def uncommonFromSentences(A, B):
    """
    :type A: str
    :type B: str
    :rtype: List[str]
    """
    words = collections.Counter(A.split() + B.split())
    for key in list(words.keys()):
        if words[key] > 1:
            del words[key]
    return list(set(words.keys()))
