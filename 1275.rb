def tictactoe(moves)
  mesh = Array.new(3) { [nil] * 3 }
  moves.each_with_index { |val, idx| mesh[val[0]][val[1]] = 'AB'[idx % 2] }

  (0..2).each do |i|
    # Row
    r = mesh[i].uniq
    return r[0] if r.length == 1 && !r[0].nil?

    # Col
    c = [mesh[0][i], mesh[1][i], mesh[2][i]].uniq
    return c[0] if c.length == 1 && !c[0].nil?
  end

  diag = [mesh[0][0], mesh[1][1], mesh[2][2]].uniq
  return diag[0] if diag.length == 1 && !diag[0].nil?

  adiag = [mesh[0][2], mesh[1][1], mesh[2][0]].uniq
  return adiag[0] if adiag.length == 1 && !adiag[0].nil?

  u = mesh.flatten.uniq
  return 'Draw' if u.length == 2 && u.include?('A') && u.include?('B')

  return 'Pending'
end
