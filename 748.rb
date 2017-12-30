def dominant_index(nums)
  return -1 if nums.empty?

  max = [nums[0], 0]
  next_max = -1
  (1...nums.length).map.with_index(1) { |i, index| [nums[i], index] }.each do |value, index|
    if value > max[0]
      next_max = max[0]
      max = [value, index]
    else
      next_max = [next_max, value].max
    end
  end

  # We cannot use max[0] / 2!!
  if max[0] >= next_max * 2
    max[1]
  else
    -1
  end
end
