def reverse_words(str)
  reverse_part = lambda do |i, j|
    while i < j
      str[i], str[j] = str[j], str[i]
      i += 1
      j -= 1
    end
  end

  str.reverse!
  word_start = 0
  iter = 0
  while iter < str.length
    if str[iter] == ' '
      reverse_part.call(word_start, iter - 1)
      word_start = iter + 1
    end
    iter += 1
  end

  reverse_part.call(word_start, iter - 1)

  str
end
