def is_one_bit_character(bits)
  len = bits.length
  # If it has only one bit, that means it mus be an one bit character
  return true if len == 1
  # We know the last bit is 0, if the bit before last bit is 0, it must be an
  # one bit character
  return true if bits[len - 2] == 0

  # We count the number of 1s before the last bit, if it is odd, then it must
  # be a two bits character
  one_count = 0
  (0..len - 2).reverse_each do |index|
    if bits[index] == 1
      one_count += 1
    else
      break
    end
  end
  if one_count % 2 == 1
    false
  else
    true
  end
end
