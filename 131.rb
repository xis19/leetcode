def partition(s)
  cache = {}

  is_palindrome = lambda do |str, last|
    i, j = 0, last
    while i < j
      return false if str[i] != str[j]
      i += 1
      j -= 1
    end
    true
  end

  check = lambda do |str|
    return [[]] if str.empty?
    return cache[str] if cache.include?(str)

    cache[str] = (0...str.length).select do |l|
      is_palindrome.call(str, l) 
    end.map do |l|
      check.call(str[l + 1..-1]).map do |i|
        [str[0..l]] + i
      end
    end.flatten(1)

  end

  check.call(s)
end
