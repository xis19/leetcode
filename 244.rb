class WordDistance
  def initialize(words)
    @hash_map = Hash.new { |hash, v| hash[v] = Array.new }
    words.each_with_index { |v, i| @hash_map[v].push(i) }
  end

  def shortest(word1, word2)
    @hash_map[word1].product(@hash_map[word2]).map { |i, j| (i - j).abs }.min
  end
end
