def largest_unique_number(a)
  h = Hash.new(0)
  a.each { |v| h[v] += 1 }
  sorted = h.map { |k, v| [v, k] }.select{ |v| v[0] == 1}.map { |v| v[1] }.sort
  sorted.empty? ? -1 : sorted.last
end
