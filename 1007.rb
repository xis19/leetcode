def min_domino_rotations(a, b)
  return -1 if a.size == 0

  # The possible values that can cause a domino row will be determined by the
  # first pair.
  candidates = {
    a[0] => [0, 0],
    b[0] => [0, 0]
  }

  len = a.size

  a.zip(b).each do |aa, bb|
    return -1 unless candidates.include?(aa) || candidates.include?(bb)

    if aa == bb
      # If for a pair, the values are the same, then the possible candidate
      # can ONLY be this value.
      candidates.delete_if { |k| k != aa }
      len -= 1
      next
    end

    candidates[aa][0] += 1 if candidates.include?(aa)
    candidates[bb][1] += 1 if candidates.include?(bb)
  end

  candidates.each { |k, v| return v.min if v[0] + v[1] == len }
  return -1
end
