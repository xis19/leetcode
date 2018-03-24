def findMissingRanges(nums, lower, upper):
    result = []

    nums.append(upper + 1)
    last_lower = lower
    for num in nums:
        if num == last_lower:
            pass
        elif num - 1 == last_lower:
            result.append(str(last_lower))
        elif num > last_lower:
            result.append('{}->{}'.format(last_lower, num - 1))
        last_lower = num + 1
    return result
