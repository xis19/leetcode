def find_ocurrences(text, first, second)
  data = text.split
  return [] if data.size <= 2

  d0, d1 = nil, nil
  data.select do |item|
    x, d0, d1 = d0, d1, item
    x == first && d0 == second
  end
end
