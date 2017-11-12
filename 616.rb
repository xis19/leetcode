require 'set'

def add_bold_tag(s, strs)
  s_len = s.length
  tag_range = [0] * s_len

  strs_len_dict = Hash.new { |hash, v| hash[v] = Set.new }
  strs.each { |ss| strs_len_dict[ss.length].add(ss) }

  (0...s_len).each do |i|
    strs_len_dict.each do |len, ss|
      next if i + len > s_len
      part = s[i..i + len - 1]
      if ss.include?(part)
        (i..i + len - 1).each { |j| tag_range[j] = 1 }
        next
      end
    end
  end

  is_bold = false
  result = ''
  (0...s_len).each do |d|
    i = tag_range[d]
    if is_bold && i == 0
      result += '</b>'
      is_bold = false
    elsif !is_bold && i == 1
      result += '<b>'
      is_bold = true
    end
    result += s[d]
  end
  result += '</b>' if is_bold

  result
end
