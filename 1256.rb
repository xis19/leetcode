def encode(num)
  # 0 -- 2 ^ 0 - 1 -- ''
  # 1 -- 2 ^ 1 - 1 -- '0'
  # 3 -- 2 ^ 2 - 1 -- '00'
  # 7 -- 2 ^ 3 - 1 -- '000'

  # Find the largest 2^n - 1 that smaller than num
  w = 0
  w += 1 until 2 ** w - 1 > num
  w -= 1

  num -= 2 ** w - 1

  r = []
  while num > 0
    r.push(num % 2)
    num /= 2
  end

  r.push(0) while r.length < w
  r.reverse!

  r.map { |i| i.to_s }.join
end

puts encode(0)
puts encode(1)
puts encode(2)
puts encode(3)
puts encode(4)
puts encode(5)
puts encode(6)
puts encode(7)
puts encode(8)
puts encode(9)
puts encode(10)
