def to_goat_latin(s)
  s.split.map.with_index do |word, index|
    if ['a', 'e', 'i', 'o', 'u'].include? word[0].downcase
      word
    else
      word[1..-1] + word[0]
    end + 'ma' + 'a' * (index + 1)
  end.join(' ')
end
