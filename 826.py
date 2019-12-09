import bisect

def maxProfitAssignment(difficulty, profit, worker):
    # Sort by difficulty
    _1, _2 = zip(*sorted(zip(difficulty, profit)))
    difficulty = list(_1)
    profit = list(_2)

    # Adjust profit -- if a job has higher difficulty but lower profit, amend it
    # so it has the higher profit -- worker can handle high difficulty will
    # always handle low difficulty
    p = profit[0]
    for i in range(1, len(profit)):
        if profit[i] > p:
            p = profit[i]
        else:
            profit[i] = p

    # Find the job the worker could do with highest difficulty
    result = 0
    for d in worker:
        i = bisect.bisect_right(difficulty, d)
        # Maybe the worker is too weak to do anything
        if i != 0:
            result += profit[i - 1]

    return result
