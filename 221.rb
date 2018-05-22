def maximal_square(nums)
  rr = nums.length
  return 0 if rr == 0
  cc = nums[0].length
  return 0 if cc == 0

  dp_mat = (0...rr).map { [0] * cc }.to_a

  (0...rr).each { |i| dp_mat[i][0] = nums[i][0].ord - '0'.ord }
  (0...cc).each { |i| dp_mat[0][i] = nums[0][i].ord - '0'.ord }

  (1...rr).each do |r|
    (1...cc).each do |c|
      next if nums[r][c] == '0'

      # DP Formula
      # dp[r][c] = min(dp[r - 1][c], dp[r][c -1]) + 1
      # The current cell could be the right-bottom corner of a square, and the
      # dimension of the square can be determined by its left/top element:
      #
      #    1 1 1        1 1 1       0 1 1
      #    1 2 2        1 2 2       0 1 2
      #    1 2 3        0 1 2       1 1 2
      #
      # etc. Determined by the minimum value
      dp_mat[r][c] = [dp_mat[r - 1][c], dp_mat[r][c - 1], dp_mat[r - 1][c - 1]].min + 1
    end
  end

  max = dp_mat.map { |i| i.max }.max
  max * max
end
