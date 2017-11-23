def self_dividing_numbers(left, right)
  (left..right).select do |value|
    v = value
    res = true
    while v > 0
     t = v % 10
     v = v / 10
     if t == 0 || value % t != 0
       res = false
       break
     end
    end
    res
  end.to_a
end
