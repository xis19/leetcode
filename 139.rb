def word_break(s, words)
  length = s.length

  dp = [0] * length

  word_length = words.map { |w| w.length }.to_a
  ww = words.zip(word_length)

  ww.each do |word, len|
    dp[len - 1] = 1 if s.start_with?(word)
  end

  (0...length).each do |index|
    next if dp[index] == 0  
    ww.each do |word, len|
      dp[index + len] = 1 if s[index + 1..-1].start_with?(word)
    end
  end

  dp.last == 1
end
