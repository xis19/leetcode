def cal_points(ops)
  result = []
  ops.each do |op|
    if op =~ /^[+-]?\d+$/
      result.push op.to_i
    else
      case op
      when 'C'
        result.pop
      when 'D'
        result.push result[-1] * 2
      when '+'
        result.push result[-1] + result[-2]
      end
    end
  end
  result.reduce(:+)
end
