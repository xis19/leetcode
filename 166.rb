def fraction_to_decimal(numerator, denominator)
  sgn = numerator * denominator < 0 ? '-' : ''

  numerator = numerator.abs
  denominator = denominator.abs
  integer_section = numerator / denominator

  modulus = numerator % denominator
  return sgn + integer_section.to_s if modulus == 0


  numerator = modulus * 10
  digits = []
  cyclic = nil
  used_numerators = []
  while true
    int_part = numerator / denominator
    digits.push(int_part)
    used_numerators.push(numerator)

    modulus = numerator % denominator
    break if modulus == 0

    numerator = modulus * 10
    if used_numerators.include? numerator
      cyclic = used_numerators.find_index(numerator)
      break
    end
  end

  if cyclic.nil?
    "#{sgn}#{integer_section}.#{digits.map { |i| i.to_s }.reduce(:+)}"
  else
    "#{sgn}#{integer_section}.#{(0...cyclic).map { |i| digits[i].to_s }.reduce(:+)}(#{(cyclic...digits.length).map{ |i| digits[i].to_s }.reduce(:+)})"
  end
end
