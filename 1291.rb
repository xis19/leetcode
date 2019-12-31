def sequential_digits(low, high)
  # The total number of sequential digits are limited
  # We generate all of them
  seq_digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  current_route = [1, 2, 3, 4, 5, 6, 7, 8, 9]
  new_route = nil

  while true
    new_route = []

    current_route.each do |v|
      d = v % 10 + 1
      new_route.push(v * 10 + d) if d < 10
    end

    seq_digits += new_route
    current_route = new_route

    break if new_route.empty?
  end

  seq_digits.select { |i| low <= i && i <= high }.to_a
end

