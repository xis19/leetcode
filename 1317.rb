def get_no_zero_integers(n)
  1.upto(n - 1).each do |i|
    num = i.to_s
    counterpart = (n - i).to_s
    next if num.include?('0') || counterpart.include?('0')
    return [i, n - i]
  end
end
