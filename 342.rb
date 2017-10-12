require 'set'

POWER_FOUR_32BIT = Set.new [
  1,
  1 << 2,
  1 << 4,
  1 << 6,
  1 << 8,
  1 << 10,
  1 << 12,
  1 << 14,
  1 << 16,
  1 << 18,
  1 << 20,
  1 << 22,
  1 << 24,
  1 << 26,
  1 << 28,
  1 << 30
]

def is_power_of_four(num)
  POWER_FOUR_32BIT.include?(num)
end
