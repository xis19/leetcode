# Multiple ways of doing it, e.g. using JSON
# Here I will use string with length


def encode(strs)
  strs.map { |str| str.length.to_s + '|' + str }.to_a.join
end

def decode(s)
  result = Array.new
  i = 0
  while i < s.length
    len = 0
    while s[i] != '|'
      len *= 10
      len += s[i].ord - '0'.ord
      i += 1
    end
    i += 1
    result.push(s[i...i + len])
    i += len
  end
  result
end
