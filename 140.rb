def word_break(s, words)
  cache = Hash.new
  traverse = lambda do |str|
    return cache[str] if cache.include?(str)

    result = []
    words.each do |word|
      next unless str.start_with?(word)
      if str == word
        result.push([word])
      else
        remain = traverse.call(str[word.length..-1])
        next if remain.nil?
        result.concat(remain.map { |i| [word] + i }.to_a)
      end
    end


    if result.length == 0
      cache[str] = nil
    else
      cache[str] = result
    end

    cache[str]
  end

  (traverse.call(s) or []).map { |i| i.join(' ') }.to_a
end
