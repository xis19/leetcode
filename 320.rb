def generate_abbreviations(word)
  if word.empty?
    ['']
  else
    [word] + (1..word.length).map do |len|
      (0..word.length - len).map do |i|
        if word.length - (i + len) < 2
          word[0...i] + len.to_s + word[i + len..-1]
        else
          generate_abbreviations(word[i + len + 1..-1]).map do |w|
            word[0...i] + len.to_s + word[i + len] + w
          end
        end
      end
    end.flatten!
  end
end
