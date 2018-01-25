def permute_unique(nums)
  nums.sort!

  backtrack = lambda do |list|
    if list.empty?
      [[]]
    else
      prev = nil
      result = []
      list.each.with_index do |l, i|
        if l == prev
          next
        else
          result.concat(backtrack.call(list[0...i] + list[i + 1..-1]).map { |r| [l] + r })
          prev = l
        end
      end
      result
    end
  end

  backtrack.call(nums)
end
