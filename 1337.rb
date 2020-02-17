def k_weakest_rows(mat, k)
  mat.map.with_index { |v, i| [v.reduce(:+), i] }.sort { |u, v| u[0] <=> v[0] }.map { |v| v[1] }[0...k]
end
