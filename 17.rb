BUTTONS = {
  '0' => ' ',
  '2' => 'abc',
  '3' => 'def',
  '4' => 'ghi',
  '5' => 'jkl',
  '6' => 'mno',
  '7' => 'pqrs',
  '8' => 'tuv',
  '9' => 'wxyz'
}

def letter_combinations(input)
  return [] if input.empty?
  construct = ->(digits) do
    if digits.empty?
      ['']
    else
      BUTTONS[digits[0]].chars.product(construct.call(digits[1..-1]))
    end
  end
  construct.call(input).map { |i| i.join }
end
