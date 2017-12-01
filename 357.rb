def count_numbers_with_unique_digits(n)
  return 0 if n > 10
  return 1 if n == 0
  return 10 if n == 1

  # choose 0-9 digits over n slots
  # the first slot can't be 0

  # 1st digit must be 1-9
  # the remaining digits can be 0-9
  all = 9 * ((9 - (n - 2)..9).inject(:*) or 1)

  all + count_numbers_with_unique_digits(n - 1)
end
