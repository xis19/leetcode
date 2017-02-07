def find_relative_ranks(nums)
  nums.each_with_index.to_a.sort.reverse.each_with_index.map do |data, index|
    old_index = data[1]
    if index == 0
      [old_index, 'Gold Medal']
    elsif index == 1
      [old_index, 'Silver Medal']
    elsif index == 2
      [old_index, 'Bronze Medal']
    else
      [old_index, (index + 1).to_s]
    end
  end.sort.map do |_, value|
    value
  end
end

