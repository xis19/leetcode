def valid_word_square(words)
  return true if words.length == 0
  nr = words.length
  nc = words[0].length
  return false if nr != nc

  (0...nr).each do |i|
    rr = words[i]
    cc = words.map { |w| w[i] || '' }.reduce(:+)
    return false if rr != cc
  end

  return true
end
