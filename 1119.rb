def remove_vowels(s)
  s.each_char.select { |i| ! %w(a e i o u).include?(i) }.join
end
