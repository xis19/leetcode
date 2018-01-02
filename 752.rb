def ip_to_cidr(ip, n)
  def ip_to_int(v)
    v.split('.').map.with_index { |v, i| v.to_i << ((3 - i) * 8) }.reduce(:+)
  end

  def int_to_ip(v)
    (0...4).map { |i| ((v >> (i * 8)) & 255).to_s }.reverse.join('.')
  end

  min = ip_to_int(ip)
  max = min + n

  result = []
  iterator = min
  while iterator < max
    # Count leading zeros, find maximum range
    tmp = iterator
    range = 1
    nbits_fixed = 1
    while tmp & 1 == 0
      range <<= 1
      nbits_fixed += 1
      tmp >>= 1
    end

    # Reduce the range by the max
    while iterator + range > max
      range >>= 1
      nbits_fixed -= 1
    end

    # Step the iterator, insert the range
    result.push("#{int_to_ip(iterator)}/#{32 - nbits_fixed + 1}")
    iterator += range
  end

  result
end
