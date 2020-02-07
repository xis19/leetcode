def decompress_rl_elist(nums)
  nums.each_slice(2).map { |i, j| [j] * i }.reduce(:+)
end
