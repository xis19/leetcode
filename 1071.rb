def gcd_of_strings(str1, str2)
  str1, str2 = str2, str1 if str1.size > str2.size

  str1.size.downto(1).each do |i|
    if str1.size % i == 0 && str2.size % i == 0
      str = str1[0...i]
      return str if str * (str1.size / i) == str1 && str * (str2.size / i) == str2
    end
  end

  return ''
end
