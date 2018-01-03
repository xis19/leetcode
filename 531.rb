require 'set'

def find_lonely_pixel(picture)
  col_hash = Hash.new { |hash, v| hash[v] = [] }
  row_hash = Hash.new { |hash, v| hash[v] = 0 }
  picture.each.with_index do |rr, y|
    rr.each_with_index do |v, x|
      next if v == 'W'
      col_hash[x].push(y)
      row_hash[y] += 1
    end
  end

  result = 0
  col_hash.each_pair do |col, ys|
    next if ys.length > 1
    result += (row_hash[ys[0]] == 1) ? 1 : 0
  end
  result
end
