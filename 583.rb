=begin
The problem is a typical DP problem.

  string1 = "baa"
  string2 = "aac"

  M   0 b a a
  0   0 1 2 3
  a   1 2 1 2
  a   2 3 2 1
  c   3 4 3 2

  if string1[i] == string2[j], that means it does not contribute deletion, we
  will use min(M[i - 1][j] + 1, M[i][j - 1] + 1, M[i - 1][j - 1])

  if string1[i] != string2[j], that means we need to delete one character to
  reach M[i - 1][j] or M[i][j - 1] status, or delete two characters to reach
  M[i - 1][j - 1] status.
=end
def min_distance(word1, word2)
  dp = (0..word1.length).map { [0] * (1 + word2.length) }.to_a

  (0..word1.length).each { |i| dp[i][0] = i }
  (0..word2.length).each { |i| dp[0][i] = i }

  (0...word1.length).each do |i|
    (0...word2.length).each do |j|
      dp[i + 1][j + 1] = (
        if word1[i] == word2[j]
          [dp[i][j], dp[i + 1][j] + 1, dp[i][j + 1] + 1].min
        else
          [dp[i][j] + 2, dp[i + 1][j] + 1, dp[i][j + 1] + 1].min
        end
      )
    end
  end

  dp.last.last
end

puts min_distance("sea", "eat")
puts min_distance("baaa", "acba")
