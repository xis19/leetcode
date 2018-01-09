def change(amount, coins)
  return 1 if amount == 0
  num_coins = coins.length
  return 0 if num_coins == 0

  dp = (0...num_coins).map { [0] * (amount + 1) }.to_a

  # For 0 amount, there is always exact 1 way of picking up the coins: Pick up
  # no coins
  (0...num_coins).each { |i| dp[i][0] = 1 }

  coins.each_with_index do |coin, row|
    (1..amount).each do |i|
      left = i >= coin ? dp[row][i - coin] : 0
      upper = row != 0 ? dp[row - 1][i] : 0
      dp[row][i] = left + upper
    end
  end
  dp.last.last
end
