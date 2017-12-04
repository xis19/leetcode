def largest_number(nums)
  return '0' if nums.reduce(:+) == 0
  nums.map do |num|
    num.to_s
  end.sort do |v1, v2|
    # Sort the number so we always put the string that makes the final result
    # larger first.
    v1 + v2 <=> v2 + v1
  end.reverse.reduce(:+)
end
