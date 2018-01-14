require_relative 'trie'

def replace_words(dict, sentence)
  trie = Trie.new
  dict.each { |word| trie.insert(word) }

  sentence.split(' ').map do |word|
    found = (0...word.length).each do |i|
      break i if trie.include?(word[0..i])
    end

    if found.is_a?(Fixnum)
      word[0..found]
    else
      word
    end
  end.join(' ')
end
