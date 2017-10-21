MAPPER = Hash[(0..25).map { |i| [('a'.ord + i).chr, 1 << i] }]

def max_product(words)
  r = words.map { |word| [(word.chars.map { |ch| MAPPER[ch] }.reduce(:|) or 0), word.length] }
  max = 0
  (0...r.length).each do |i|
    (i + 1...r.length).each do |j|
      max = [r[i][1] * r[j][1], max].max unless r[i][0] & r[j][0] > 0
    end
  end
  max
end
