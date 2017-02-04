import collections

def frequencySort(s):
    return ''.join(item[0] * item[1] for item in reversed(sorted(collections.Counter(s).most_common(), key=lambda i: i[1])))
