def find_permutation(s)
  # We start with 1
  # For an I, we just append the number
  #  I
  # 1, 2
  # For a D, we will do a reverse search until we reach I, so the range between
  # the last number and the nearest I is descending
  #  I  D
  # 1, 3, 2
  #  I  D  D
  # 1, 4, 3, 2
  result = [1]
  last_i = 0
  s.each_char.with_index do |ch, idx|
    i = idx + 2
    if ch == 'I'
      result.push(i)
      last_i = idx + 1
    else
      result.insert(last_i, i)
    end
  end
  result
end
