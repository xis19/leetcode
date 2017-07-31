def findErrorNums(nums: list) -> list:
    error_num = None
    for i in nums:
        v = abs(i)
        if nums[v - 1] < 0:
            error_num = v
        else:
            nums[v - 1] *= -1
    for i, v in enumerate(nums):
        if v > 0:
            missing = i + 1
    return [error_num, missing]
