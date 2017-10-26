def length_of_longest_substring_k_distinct(s, k)
  return 0 if s.empty? || k == 0

  char_use = Hash.new { |hash, v| hash[v] = 0 }

  iter1, iter2 = 0, 0
  max_length = 0
  while iter2 < s.length
    ch = s[iter2]
    char_use[ch] += 1
    while char_use.length > k
      xch = s[iter1]
      char_use[xch] -= 1
      char_use.delete(xch) if char_use[xch] == 0
      iter1 += 1
    end
    max_length = [max_length, iter2 - iter1 + 1].max
    iter2 += 1
  end
  max_length
end
