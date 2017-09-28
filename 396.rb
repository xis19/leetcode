def max_rotate_function(a)
  # F(0) = f0
  # F(1) = f0 - n * A[n - 1] + sum(A[0:n - 1]) = f0 - (n + 1) * A[n - 1] + sum(A)
  # F(2) = f1 - n * A[n - 2] + sum(A[0:n - 2]) + A[n - 1]
  #      = f1 - (n + 1) * A[n - 2] + sum(A)
  # ...
  return 0 if a.empty?
  n = a.length
  sum = a.reduce(:+)
  nsum = n * sum

  f = Array.new
  f << (0...n).zip(a).map { |i, j| i * j }.reduce(:+)
  (1...n).each do |i|
    f << f.last + sum - n * a[n - i]
  end
  f.max
end
