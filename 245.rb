def shortest_word_distance(words, word1, word2)
  hash_map = Hash.new { |hash, v| hash[v] = Array.new }
  words.each_with_index { |v, i| hash_map[v].push(i) }

  if word1 == word2
    hash_map[word1].combination(2).map { |i, j| (i - j).abs }.min
  else
    hash_map[word1].product(hash_map[word2]).map { |i, j| (i - j).abs }.min
  end
end

puts shortest_word_distance(
["practice", "makes", "perfect", "coding", "makes"],
"makes", "coding"
)
