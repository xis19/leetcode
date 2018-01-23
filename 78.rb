def subsets(nums)
  result = [[]]

  cache = []
  (backtrack = lambda do |start|
    return if start >= nums.length
    cache.push(nums[start])
    result.push(cache.dup)
    backtrack.call(start + 1)
    cache.pop
    backtrack.call(start + 1)
  end).call(0)

  result
end
