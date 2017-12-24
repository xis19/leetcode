require 'set'

def ladder_length(begin_word, end_word, word_list)
  word_length = begin_word.length
  unvisited = Set.new(word_list)

  queue = [[begin_word, 1]]
  while !queue.empty?
    word, depth = queue.shift
    return depth if word == end_word

    possible_words = Set.new
    # In this particular problem, since the word_list is huge, while word length
    # is relatively small, we just enumerate all possible word alternations and
    # check if it is in the word list, which is stored in a set and querying
    # will take only O(1). This accelerates the process.
    # The standard way of doing that is, for sure, just compare every two words
    # character by character.
    (0...word_length).each do |i|
      ('a'..'z').map do |c|
        word[0...i] + c + word[i + 1..-1]
      end.select do |w|
        unvisited.include?(w)
      end.each do |w|
        possible_words.add(w)
        queue.push([w, depth + 1])
      end
    end
    possible_words.each { |w| unvisited.delete(w) }
  end

  0
end
