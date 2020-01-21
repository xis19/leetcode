$buf = {
  1 => [0, 1],
  2 => [2]
}

def find_integers(num)
  # 1 bit   => 0 1
  # 2 bits  => 10
  # 3 bits  => 100 101
  #     generated by 100 + all(1 bit)
  # 4 bits  => 1000 1001 1010
  #     generated by 1000 + all(1 bit, 2 bits)
  # ...

  count = 0
  1.upto(31) do |nbits|
    unless $buf.include?(nbits)
      start = 1 << (nbits - 1)
      $buf[nbits] = 1.upto(nbits - 2).map { |i| $buf[i].map { |v| start + v } }.flatten
    end
    # We use binary search to accelerate, since $buf[nbits] is sorted
    incr = $buf[nbits].last <= num ? $buf[nbits].length : $buf[nbits].bsearch_index { |i| i > num }
    count += incr
    break if incr == 0
  end
  1.upto(31) do |i| puts $buf[i].length end

  count
end
