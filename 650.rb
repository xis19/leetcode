require 'mathn'

def min_steps(n)
  if n == 1
    0
  else
    # We split the number into prime factors. For prime P, it requires 1 copy
    # and P - 1 pastes => P operations. For composite number P * Q, it requires
    # 1 copy, P - 1 pastes, and 1 copy, Q - 1 pastes => P + Q operations.
    n.prime_division.map { |v, i| [v] * i }.flatten.sort.reverse.reduce(:+)
  end
end
