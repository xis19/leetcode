def combination_sum4(nums, target)
  nums.sort!

  dp = [0] * (target + 1)
  dp[0] = 1
  (1..target).each do |tgt|
    nums.each do |n|
      break if n > tgt
      dp[tgt] += dp[tgt - n]
    end
  end

  dp.last
end
