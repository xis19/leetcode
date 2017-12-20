def check_inclusion(s1, s2)
  s1len = s1.length
  s2len = s2.length

  return false if s1len > s2len

  s1map = Hash.new { |hash, v| hash[v] = 0 }
  s2map = Hash.new { |hash, v| hash[v] = 0 }

  ('a'..'z').each { |i| s1map[i.chr], s2map[i.chr] = 0, 0 }

  (0...s1len).each do |i|
    s1map[s1[i]] += 1
    s2map[s2[i]] += 1
  end

  return true if s1map == s2map
  (s1len...s2len).each do |i|
    s2map[s2[i - s1len]] -= 1
    s2map[s2[i]] += 1
    return true if s1map == s2map
  end

  false
end
