def spellchecker(wordlist, queries)
  downcase_map = ->(word) { word.downcase }
  downcase_vowel_map = ->(word) { word.downcase.gsub(/[aeiouAEIOU]/, '*') }

  downcase_word_map = Hash.new { |h, k| h[k] = [] }
  downcase_vowel_word_map = Hash.new { |h, k| h[k] = [] }
  wordlist.each do |word|
    downcase_word_map[downcase_map.call(word)].push(word)
    downcase_vowel_word_map[downcase_vowel_map.call(word)].push(word)
  end

  wordset = wordlist.to_set

  queries.map { |word|
    if wordset.include?(word)
      # When the query exactly matches a word in the wordlist
      word
    else
      # Capitalization first
      downcase = downcase_map.call(word)
      if downcase_word_map.include?(downcase)
        downcase_word_map[downcase].first
      else
        # Capitalization and vowel
        downcase_vowel = downcase_vowel_map.call(word)
        if downcase_vowel_word_map.include?(downcase_vowel)
          downcase_vowel_word_map[downcase_vowel].first
        else
          ""
        end
      end
    end
  }.to_a
end
