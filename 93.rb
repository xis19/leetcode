def restore_ip_addresses(s)
  verify = ->(start, len) do
    len > 0 && start + len <= s.length && ((len == 1 && s[start] == '0') ^ (s[start] != '0' && s[start...start + len].to_i <= 255))
  end

  restore = ->(start, remain_dots) do
    if remain_dots == 0
      if verify.call(start, s.length - start)
        [s[start..-1]]
      else
        []
      end
    else
      (1..3).map do |i|
        if verify.call(start, i)
          restore.call(start + i, remain_dots - 1).map { |r| s[start...start + i] + '.' + r }
        else
          []
        end
      end.reduce(:+)
    end
  end

  restore.call(0, 3)
end
