def repeated_string_match(a, b)
  len_a = a.length
  len_b = b.length
  
  s = a
  # Note: We need at least 2 duplication of a, even a is longer than b,
  # this ensure the situation
  #     aaaaaa + aaaaaa
  #        \---b---/
  (1..[len_b / len_a + 1, 2].max).each do |i|
    return i if s.include?(b)
    s += a
  end
  -1
end
