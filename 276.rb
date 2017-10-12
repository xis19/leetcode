def num_ways(n, k)
  if n == 0 || k == 0
    0
  else
    history = [0, k, k * k]
    # w(n) = (k - 1) * (w(n-1) + w(n-2))
    # for n posts, if we want n, n-1 have the same color, there are (k-1) *
    # w(n-2) possibilities, if we want n,n-1 have different color, there are
    # (k-1) * w(n-1) possibilities
    (3..n).each do |i|
      history << (k - 1) * (history[i - 1] + history[i - 2])
    end
    history[n]
  end
end
