def length_of_lis(nums)
  return 0 if nums.length == 0

  dp = [0] * nums.length
  dp[0] = 1

  max_len = 1

  (1...nums.length).each do |i|
    value = nums[i]
    dp[i] = (0...i).map { |t| nums[t] < value ? dp[t] : 0 }.max + 1
    max_len = [max_len, dp[i]].max
  end

  max_len
end
