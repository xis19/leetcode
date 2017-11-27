def find_pairs(nums, d)
  return 0 if d < 0
  num_hash = Hash.new { |hash, v| hash[v] = 0 }
  nums.each { |i| num_hash[i] += 1 }

  if d == 0
    num_hash.each_value.select { |v| v > 1 }
  else
    num_hash.each_key.select { |k| num_hash.include?(k + d) }
  end.map { |i| 1 }.reduce(:+) or 0
end
