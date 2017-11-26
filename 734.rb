require 'set'

def are_sentences_similar(words1, words2, pairs)
  w1len, w2len = words1.length, words2.length
  return false if w1len != w2len

  hash = Hash.new { |hash, v| hash[v] = Set.new }  
  pairs.each do |p1, p2|
    hash[p1].add(p2)
    hash[p2].add(p1)
  end

  words1.zip(words2).each do |w1, w2|
    next if w1 == w2

    return false if !hash.include?(w1) || !hash[w1].include?(w2)
  end
  true
end
