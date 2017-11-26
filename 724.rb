def pivot_index(nums)
  sum = nums.reduce(:+)

  lsum = 0
  (0...nums.length).each do |i|
    rsum = sum - lsum - nums[i]
    return i if rsum == lsum
    lsum += nums[i]
  end
  -1
end
