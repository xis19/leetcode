def minimum_swap(s1, s2)
  # for two x-y pairs, we could do a swap to get x-x + y-y
  # for two y-x pairs, similar
  # we mark them as "simple" -- 1 step
  # if we have a y-x pair, a x-y pair, we could first transform to x-y + x-y,
  # then to x-x + y-y
  # we mark it as "complex" -- 2 steps
  map = {'xx' => 0, 'yy' => 0, 'xy' => 0, 'yx' => 0}
  s1.split('').zip(s2.split('')).each do |x, y|
    m = "#{x}#{y}"
    map[m] += 1
  end
  simple = map['xy'] / 2 + map['yx'] / 2

  # Check for possible complex transform
  complex = 0
  mod_xy = map['xy'] % 2
  mod_yx = map['yx'] % 2
  return -1 if mod_xy + mod_yx == 1
  complex = 2 if mod_xy == 1 && mod_yx == 1

  simple + complex
end
