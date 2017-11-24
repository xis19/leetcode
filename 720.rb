require 'set'

def longest_word(words)
  result = ''

  word_set = Set.new(words)
  words.sort do |i, j|
    if i.length > j.length
      -1
    elsif i.length < j.length
      1
    else
      i <=> j
    end
  end.each do |word|
    if (0...word.length).map { |i| word[0..i] }.all? { |part| word_set.include?(part) }
      result = word
      break
    end
  end

  result
end
