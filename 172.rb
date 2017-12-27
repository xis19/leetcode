def trailing_zeroes(n)
  # Each factor of 5 causes a zero, since even numbers are more than 5
  # We need to count the number of factors of 5
  # Yet we need to consider, e.g. 25 has actually 2 factors of 5
  t = 5
  num_zeros = 0
  while t <= n
    num_zeros += n / t
    t *= 5
  end
  num_zeros
end
