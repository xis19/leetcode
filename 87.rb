def is_scramble(s1, s2)
  scrambles = Hash.new { |hash, val| hash[val] = Hash.new }

  scramble = lambda do |ss1, ss2|
    unless scrambles[ss1].include?(ss2)
      len = ss1.length
      if len <= 2
        scrambles[ss1][ss2] = ss1 == ss2 || ss1 == ss2.reverse
      else
        scrambles[ss1][ss2] = false
        (0..len - 2).each do |v|
          if (scramble.call(ss1[0..v], ss2[0..v]) && scramble.call(ss1[v + 1..-1], ss2[v + 1..-1]) ||
              scramble.call(ss1[0..v], ss2[len - v - 1..-1]) && scramble.call(ss1[v + 1..-1], ss2[0..len - v - 2]))
            scrambles[ss1][ss2] = true
            break
          end
        end
      end
    end

    scrambles[ss1][ss2]
  end
  scramble.call(s1, s2)
end
