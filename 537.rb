def complex_number_multiply(a, b)
  ra, ia = a.tr('i', '').split('+').map { |i| i.to_i }
  rb, ib = b.tr('i', '').split('+').map { |i| i.to_i }

  a = ra * rb - ia * ib
  b = ra * ib + rb * ia

  "#{a}+#{b}i"
end
