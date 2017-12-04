FIXNUM_MAX = (2**(0.size * 8 -2) -1)

def update_matrix(matrix)
  m = matrix.size
  n = matrix[0].size

  # Scan top-left to bottom-right
  (0...m).each do |rr|
    (0...n).each do |cc|
      next if matrix[rr][cc] == 0
      upper = rr > 0 ? matrix[rr - 1][cc] + 1 : FIXNUM_MAX
      left = cc > 0 ? matrix[rr][cc - 1] + 1 : FIXNUM_MAX
      matrix[rr][cc] = [upper, left].min
    end
  end

  # Scan bottom-right to top-left
  (0...m).reverse_each do |rr|
    (0...n).reverse_each do |cc|
      next if matrix[rr][cc] == 0
      lower = rr < m - 1 ? matrix[rr + 1][cc] + 1 : FIXNUM_MAX
      right = cc < n - 1 ? matrix[rr][cc + 1] + 1 : FIXNUM_MAX
      matrix[rr][cc] = [matrix[rr][cc], lower, right].min
    end
  end

  matrix
end
