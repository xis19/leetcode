def find_repeated_dna_sequences(s)
  return [] if s.length <= 10
  seq = Hash.new { |hsh, v| hsh[v] = 0 }
  sel = s[0..9]
  seq[sel] = 1

  s[10..-1].each_char do |ch|
    sel = sel[1..-1] + ch
    seq[sel] += 1
  end

  seq.select { |k, v| v > 1 }.map { |k, v| k }.to_a
end
