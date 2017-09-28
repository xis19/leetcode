def is_strobogrammatic(num)
  map = ['0', '1', 'x', 'x', 'x', 'x', '9', 'x', '8', '6']
  num.to_s.reverse.chars.map { |ch| map[ch.to_i] }.reduce(:+) == num.to_s
end
