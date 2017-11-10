require 'set'

DIGIT_RANGE = ('0'..'9')
ZERO_ASCII = '0'.ord
OPS = Set.new ['+', '-', '*', '/']
PRIORITY = {
  nil => -999,
  '+' => 1,
  '-' => 1,
  '*' => 2,
  '/' => 2
}

def calculate(s)
  val_stack = []
  oper_stack = []
  evaluate = lambda do
    v1 = val_stack.pop
    v2 = val_stack.pop

    val_stack.push(case oper_stack.pop
  when '+'
    v2 + v1
  when '-'
    v2 - v1
  when '*'
    v2 * v1
  when '/'
    v2 / v1
  end)
end

  i = 0
  val = 0
  while i < s.length
    ch = s[i]
    if ch == ' '
      nil
    elsif DIGIT_RANGE.include?(ch)
      val *= 10
      val += ch.ord - ZERO_ASCII
    elsif OPS.include?(ch)
      val_stack.push(val)
      val = 0
      p = PRIORITY[ch]
      evaluate.call while !oper_stack.empty? && p <= PRIORITY[oper_stack.last]
      oper_stack.push(ch)
    end
    i += 1
  end

  val_stack.push(val)
  evaluate.call while !oper_stack.empty?

  val_stack.last
end
