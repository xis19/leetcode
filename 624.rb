def max_distance(arrays)
  min, max = arrays[0][0], arrays[0][-1]
  max_dist = -1

  arrays[1..-1].each do |a|
    max_dist = [(max - a[0]).abs, (a[-1] - min).abs, max_dist].max
    max = [max, a[-1]].max
    min = [min, a[0]].min
  end

  max_dist
end
