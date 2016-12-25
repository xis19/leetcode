def generate_parenthesis(n)
  generator = ->(s, l, r) do
    if l == 0
      [s + ')' * r]
    else
      generator.call(s + '(', l - 1, r) + (r > l ? generator.call(s + ')', l, r - 1) : [])
    end
  end
  generator.call('', n, n)
end
