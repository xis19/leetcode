def find_longest_word(s, d)
  s_len = s.length
  is_substring = lambda do |str|
    si, strlen = 0, str.length
    (0...s_len).map { |i| s[i] }.each do |ch|
      si += 1 if ch == str[si]
      return true if si == strlen
    end
    false
  end
  longest, str = 0, ''
  d.sort.each do |s|
    if is_substring.call(s) && s.length > longest
      longest = s.length
      str = s
    end
  end
  str
end
