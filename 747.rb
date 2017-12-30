def min_cost_climbing_stairs(cost)
  dp = [nil] * cost.length
  dp[0] = 0
  dp[1] = 0
  (2...cost.length).each do |i|
    dp[i] = [dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]].min
  end
  dp.last
end
