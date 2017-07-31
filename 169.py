import collections

def majorityElement(nums: list) -> int:
    counter = collections.Counter()
    counter.update(nums)
    return counter.most_common(1)[0][0]
