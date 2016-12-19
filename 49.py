def groupAnagrams(self, strs):
    dict_result = collections.defaultdict(list)
    for s in strs:
        dict_result[''.join(sorted(s))].append(s)
    return dict_result.values()
