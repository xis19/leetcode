def check_valid_string(s)
  s_length = s.length
  cache = Hash.new
  verify = lambda do |bras, kets, iter|
    key = [bras, kets, iter]
    return cache[key] if cache.include?(key)

    while iter < s_length
      case s[iter]
      when '('
        bras += 1
        iter += 1
      when ')'
        kets += 1
        if kets > bras
          cache[key] = false
          return false
        else
          iter += 1
        end
      when '*'
        empty_result = verify.call(bras, kets, iter + 1)
        bra_result = verify.call(bras + 1, kets, iter + 1)
        ket_result = (kets + 1 <= bras) ? verify.call(bras, kets + 1, iter + 1) : false
        cache[key] = bra_result || ket_result || empty_result
        return cache[key]
      end
    end
    cache[key] = bras == kets
  end

  verify.call(0, 0, 0)
end
