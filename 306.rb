def is_additive_number(num)
  total_length = num.length

  try = lambda do |v1, v2, remain|
    sum = v1 + v2
    ssum = sum.to_s
    if ssum == remain
      true
    elsif !remain.start_with? ssum
      false
    else
      try.call(v2, sum, remain[ssum.length..-1])
    end
  end

  (1..total_length / 2).each do |l1|
    v1 = num[0...l1].to_i
    next if num[0] == '0' && v1 != 0
    (1..total_length / 2).each do |l2|
      v2 = num[l1...l1 + l2].to_i
      break if num[l1] == '0' && v2 != 0
      return true if try.call(v1, v2, num[l1 + l2..-1])
    end
  end
  false
end
