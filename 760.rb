def anagram_mappings(a, b)
  h = b.each.with_index.to_h
  a.map { |v| h[v] }.to_a
end
