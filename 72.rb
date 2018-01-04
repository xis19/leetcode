def min_distance(word1, word2)
  dp = (0..word1.length).map { |i| [0] * (word2.length + 1) }.to_a
  (1..word2.length).each { |i| dp[0][i] = i }
  (1..word1.length).each { |i| dp[i][0] = i }

  (1..word1.length).each do |w1|
    (1..word2.length).each do |w2|
      c1, c2 = word1[w1 - 1], word2[w2 - 1]
      dp[w1][w2] = (
        if c1 != c2
          [dp[w1 - 1][w2 - 1], dp[w1 - 1][w2], dp[w1][w2 - 1]].min + 1
        else
          dp[w1 - 1][w2 - 1]
        end
      )
    end
  end

  dp.last.last
end
