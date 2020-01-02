def sum_zero(n)
  x = (1..n / 2).to_a
  invx = x.map { |v| -v }
  if n % 2 != 0
    invx + [0] + x
  else
    invx + x
  end
end

