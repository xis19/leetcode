import sys

def maxProfit(prices: list) -> int:
    max_profit = 0
    previous_min = sys.maxsize
    for i in prices:
        if i < previous_min:
            previous_min = i
        max_profit = max(max_profit, i - previous_min)
    return max_profit
