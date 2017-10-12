def valid_palindrome(s)
  def valid(s)
    s.nil? || s.reverse == s
  end

  i = 0
  j = s.length - 1
  while i < j
    return valid(s[i + 1..j]) || valid(s[i..j-1]) if s[i] != s[j]
    i += 1
    j -= 1
  end
  return true
end
