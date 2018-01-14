def longest_line(matrix)
  # This can be done easily by scanning each row, each column and each diagonal
  # lines. We could also use DP for row/columns/diag/anti-diag. This takes
  # O(4nm) space complexity but with less time complexity, O(nm)

  m = matrix.length
  return 0 if m == 0
  n = matrix[0].length
  return 0 if n == 0

  dp = (0..m).map { (0..n + 1).map { [0] * 4 }.to_a }.to_a

  max = 0
  (1..m).each do |r|
    (1..n).each do |c|
      v = matrix[r - 1][c - 1]
      next if v == 0

      dp[r][c][0] = dp[r][c - 1][0] + 1
      dp[r][c][1] = dp[r - 1][c - 1][1] + 1
      dp[r][c][2] = dp[r - 1][c][2] + 1
      dp[r][c][3] = dp[r - 1][c + 1][3] + 1

      max = [max, dp[r][c].max].max
    end
  end

  max
end
