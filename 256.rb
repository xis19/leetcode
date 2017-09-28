def min_cost(costs)
  return 0 if costs.length == 0

  rr, gg, bb = costs[0]
  (1...costs.length).each do |i|
    r, g, b = costs[i]

    rx = r + [gg, bb].min
    gx = g + [rr, bb].min
    bx = b + [rr, gg].min

    rr = rx
    gg = gx
    bb = bx
  end
  [rr, gg, bb].min
end
