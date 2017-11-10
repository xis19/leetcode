def min_sub_array_len(s, nums)
  return 0 if nums.length == 0

  sum = nums[0]
  liter, riter = 0, 0
  min_size = nums.length + 1

  (riter += 1; sum += nums[riter]) while sum < s && riter < nums.length - 1

  return 0 if sum < s && riter == nums.length - 1
  min_size = [min_size, riter - liter + 1].min

  while true
    (sum -= nums[liter]; liter += 1) while liter < riter && sum - nums[liter] >= s
    min_size = [min_size,  riter - liter + 1].min
    break if riter == nums.length - 1
    (riter += 1; sum += nums[riter])
  end

  min_size
end
