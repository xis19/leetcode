def diff_ways_to_compute(input)
  # NOTE: For Ruby, "2-1-1" will be split into "", "-", "-" since the leading
  # \d is also a match
  operators = input.split(/\d+/)[1..-1]
  values = input.split(/[+\-*]/).map { |i| i.to_i }

  cache = Hash.new

  evaluate = lambda do |val_l, val_r|
    if val_l == val_r
      [values[val_l]]
    else
      unless cache.include?([val_l, val_r])
        result = []

        (val_l...val_r).each do |val_i|
          lhs = evaluate.call(val_l, val_i)
          rhs = evaluate.call(val_i + 1, val_r)
          op = operators[val_i]

          result.concat(lhs.product(rhs).map do |l, r|
            case op
            when '+' then l + r
            when '-' then l - r
            when '*' then l * r
            end
          end)
        end
        
        cache[[val_l, val_r]] = result
      end
      cache[[val_l, val_r]]
    end
  end

  evaluate.call(0, values.length - 1)
end
