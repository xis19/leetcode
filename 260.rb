def single_number(nums)
  # The trick is, first we use xor to get the xor of two numbers
  xor = nums.reduce(:^)

  # Now our xor must have a 1 bit, where one number has bit 0 and the other has
  # bit 1. We find this bit, and split the nums by two groups base on this bit.
  # Then the two numbers will be unique in each group.
  bit = 0
  while xor & 1 != 1
    xor >>= 1
    bit += 1
  end
  mask = 1 << bit

  group1 = nums.select { |i| i & mask != 0 }.to_a
  group2 = nums.select { |i| i & mask == 0 }.to_a
  [group1.reduce(:^), group2.reduce(:^)]
end
