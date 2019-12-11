def subtract_product_and_sum(n)
  a = n.to_s.each_char.to_a.map { |i| i.to_i }
  p = a.reduce(:*)
  s = a.reduce(:+)
  p - s
end
