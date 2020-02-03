def validSubarrays(nums: List[int]) -> int:
    # It would be easier to reverse the array, and find the rightmost element of
    # the subarray is no larger than other elements in the subarray
    #
    # We use a stack to store the minimum number met so far. If a new incoming
    # number is:
    #   1. Less or equal than the first number in the stack, we pop the stack
    #   until we reach a number smaller than it. The index of the number that is
    #   on the top of the stack indicates the number of valid subarrays that
    #   ends with the incoming number.
    #   2. Larger than the first number, just push it.
    # Note the top of the stack is the fist number that is smaller than the
    # current number.

    rev = list(reversed(nums))
    stack = []
    result = 0
    for index, num in enumerate(rev):
        while len(stack) > 0 and num <= stack[-1][0]:
            stack.pop()
        if len(stack) == 0:
            result += index + 1
        else:
            result += index - stack[-1][1] + 1
        stack.append((num, index))
    return result
