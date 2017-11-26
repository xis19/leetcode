def compress(chars)
  len = chars.length
  return len if len <= 1

  ch, count = chars[0], 1
  li, ri = 0, 1

  while ri <= len
    if chars[ri] == ch
      count += 1
    else
      # Write the count
      if count > 1
        count_str = count.to_s
        (0...count_str.length).each do |i|
          li += 1
          chars[li] = count_str[i]
        end
      end

      ch, count = chars[ri], 1

      # We used the fact that in Ruby, out-of-range access to an array causes
      # nil return, but we actually do not want to include nil in our returning
      # string.
      unless chars[ri].nil?
        li += 1
        chars[li] = ch
      end
    end
    ri += 1
  end

  chars.pop(len - li - 1)
  chars.length
end
