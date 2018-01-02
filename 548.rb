require 'set'

def split_array(nums)
  len = nums.length
  # We first generate two sum arrays, one from left to right, and one from right
  # to left.
  slr = [nums.first] * len
  srl = [nums.last] * len
  (1...len).each do |i|
    slr[i] = slr[i - 1] + nums[i]
    srl[len - (i + 1)] = srl[len - i] + nums[len - (i + 1)]
  end

  # Locate duplicate number pairs, fill up possible i, k values
  slr_values = Set.new(slr)
  srl_values = Set.new(srl)
  duplicate_values = slr_values & srl_values
  possible_value = Hash.new { |hash, v| hash[v] = {lhs: [], rhs: []} }
  (0...len).each do |i|
    possible_value[slr[i]][:lhs].push(i + 1) if duplicate_values.include?(slr[i]) && i + 1 < len
    possible_value[srl[i]][:rhs].push(i - 1) if duplicate_values.include?(srl[i]) && i - 1 >= 0
  end

  # Now enumerate every possible value i and k, and find j
  possible_value.each_pair do |s, ik|
    ik[:lhs].product(ik[:rhs]).each do |i, k|
      (i + 2..k - 2).each do |j|
        return true if slr[j - 1] - slr[i] == s && srl[j + 1] - srl[k] == s
      end
    end
  end

  false
end
