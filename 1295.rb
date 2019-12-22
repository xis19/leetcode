def find_numbers(nums)
  nums.select { |i| i.to_s.length % 2 == 0 }.count
end

