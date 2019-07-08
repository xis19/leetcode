MAPPER = {
  't' => true,
  'f' => false
}

OPS = ['!', '&', '|']
VALUES = ['t', 'f']

def evaluate(op, values)
  case op
  when '!'
    !values.first
  when '&'
    values.reduce(:&)
  when '|'
    values.reduce(:|)
  end
end

def parse_bool_expr(expression)
  op_stack = Array.new
  expression.each_char do |ch|
    next if ch == '(' || ch == ','
    if OPS.include?(ch)
      op_stack.push(ch)
    elsif VALUES.include?(ch)
      op_stack.push(MAPPER[ch])
    else
      # ')'
      s = Array.new
      while !OPS.include?(op_stack.last)
        s.push(op_stack.last)
        op_stack.pop
      end

      op = op_stack.last
      op_stack.pop
      op_stack.push(evaluate(op, s))
    end
  end

  op_stack.first
end
