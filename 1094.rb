def car_pooling(trips, capacity)
  trips
    .map { |c, s, e| [[s, c], [e, -c]] }
    .flatten(1)
    .sort
    .each do |_, c|
      capacity -= c
      return false if capacity < 0
    end
  true
end
