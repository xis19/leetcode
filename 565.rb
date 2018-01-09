def array_nesting_recursive(nums)
  len = nums.length
  ring = Hash.new

  max_length = 0

  traverse = lambda do |index|
    unless ring.include?(index)
      # We first touch the index, so the recursion has a terminate point
      ring[index] = 0
      ring[index] = traverse.call(nums[index]) + 1
      max_length = [ring[index], max_length].max
    end
    ring[index]
  end

  (0...nums.length).each do |i|
    traverse.call(i)
  end

  max_length
end

def array_nesting(nums)
  len = nums.length
  ring = Hash.new
  max_length = 0

  nums.each.with_index do |value, index|
    next if ring.include?(index)

    history = [index]
    iterator = value
    while iterator != index
      history.push(iterator)
      iterator = nums[iterator]
    end
    # i + 1 because the last element in the history connects to the *index*
    history.reverse.each_with_index { |h, i| ring[h] = i + 1 }

    max_length = [ring[index], max_length].max
  end

  max_length
end
