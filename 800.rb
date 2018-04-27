CHARS = '0123456789abcdef'
VALUES = [
  0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
  0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
]

def similar_rgb(color)
  '#' + [1..2, 3..4, 5..6].map { |clr| color[clr].to_i(16) }.map do |clr|
    CHARS[VALUES.map { |v| (clr - v) ** 2 }.to_a.each_with_index.min[1]] * 2
  end.reduce(:+)
end
