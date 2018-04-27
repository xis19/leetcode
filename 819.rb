def most_common_word(paragraph, banned)
  counter_hash = Hash.new { |hash, v| hash[v] = 0 }
  paragraph.split.map { |word| word.downcase.gsub(/[^a-zA-Z]/, '') }.each { |word| counter_hash[word] += 1 }
  counter_hash.map { |k, v| [v, k] }.select { |item| !banned.include?(item[1]) }.sort[-1][1]
end
