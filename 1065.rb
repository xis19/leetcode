def index_pairs(text, words)
  words.map { |word|
    0.upto(text.length - 1)
      .select { |i| text[i..-1].start_with?(word) }
      .map { |i| [i, i + word.length - 1] }
  }.flatten(1).sort
end
