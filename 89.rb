# @param {Integer} n
# @return {Integer[]}
def gray_code(n)
  if n == 0
    [0]
  else
    v = gray_code(n - 1)
    v + v.reverse.map { |i| i + (1 << (n - 1)) }.to_a
  end
end
