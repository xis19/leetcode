def valid_square(p1, p2, p3, p4)
  def norm2(i, j)
    (i[0] - j[0]) ** 2 + (i[1] - j[1]) ** 2
  end

  h = Hash.new { 0 }
  h[norm2(p1, p2)] += 1
  h[norm2(p2, p3)] += 1
  h[norm2(p3, p4)] += 1
  h[norm2(p4, p1)] += 1
  h[norm2(p1, p3)] += 1
  h[norm2(p2, p4)] += 1

  h.length == 2 && h.values.sort == [2, 4]
end
