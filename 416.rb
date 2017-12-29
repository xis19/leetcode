require 'set'

def can_partition(nums)
  sum = nums.reduce(:+)
  return false if sum % 2 == 1
  half_sum = sum / 2

  # We pick up numbers from nums to see if we can have a sum of half_sum
  # This is a 0/1 knapsack problem
  # However in this case the DP table can be reduced to a set
  possible_sums = Set.new
  nums.each do |num|
    tmp_sums = possible_sums.dup
    possible_sums.each { |v| tmp_sums.add(v + num) }
    tmp_sums.add(num)
    tmp_sums, possible_sums = possible_sums, tmp_sums
    return true if possible_sums.include?(half_sum)
  end
  false
end
