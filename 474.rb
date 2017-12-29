def find_max_form_slow(strs, m, n)
  data = strs.map { |s| [s.count('0'), s.count('1')] }
  num_data = data.length

  cache = Hash.new
  recursive = lambda do |i, num0, num1|
    if cache.include? [i, num0, num1]
      ;
    elsif num0 < 0 || num1 < 0
      cache[[i, num0, num1]] = nil
    elsif i >= num_data
      cache[[i, num0, num1]] = 0
    else
      non_inclusive = recursive.call(i + 1, num0, num1)
      inclusive = recursive.call(i + 1, num0 - data[i][0], num1 - data[i][1])
      inclusive += 1 unless inclusive.nil?

      cache[[i, num0, num1]] = [non_inclusive, inclusive].select { |i| !i.nil? }.max
    end

    cache[[i, num0, num1]]
  end

  recursive.call(0, m, n)
end


def find_max_form(strs, m, n)
  # DP strategy, we only need the most recent status, so reduce the dimension
  # from 3D DP to 2D dp

  # NOTE we need to differentiate between "a state cannot be reachable" (nil) or
  # "a state with 0 string can form"
  dp = (0..m).map { [nil] * (n + 1) }.to_a
  dp[m][n] = 0
  max = 0
  strs.each do |str|
    n0, n1 = str.count('0'), str.count('1')
    (0..m - n0).each do |mm|
      (0..n - n1).each do |nn|
        next if dp[mm + n0][nn + n1].nil?
        # We need to make sure we always use best solution
        dp[mm][nn] = [dp[mm][nn] || 0, dp[mm + n0][nn + n1] + 1].max
        max = [max, dp[mm][nn]].max
      end
    end
  end
  max
end
