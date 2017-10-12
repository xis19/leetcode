def valid_word_abbreviation(word, abbr)
  wi, ai = 0, 0
  wl, al = word.length, abbr.length
  while wi < wl && ai < al
    if word[wi] == abbr[ai]
      wi += 1
      ai += 1
    elsif abbr[ai] =~ /[0-9]/
      index = abbr[ai..-1].to_i
      return false if index == 0
      wi += index
      ai += index.to_s.length
    else
      return false
    end
  end
  return wi == wl && ai == al
end
