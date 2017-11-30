def compute_area(a, b, c, d, e, f, g, h)
  # The area = (AB)-(CD) + (EF)-(GH) - overlap
  abcd = (c - a) * (d - b)
  efgh = (g - e) * (h - f)
  overlap = [[h, d].min - [b, f].max, 0].max * [[g, c].min - [e, a].max, 0].max
  return abcd + efgh - overlap
end
