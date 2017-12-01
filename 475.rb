def find_radius(houses, heaters)
  # We find the nearest heater for each house
  heaters.sort!
  heaters.unshift(-Float::INFINITY)
  heaters.push(Float::INFINITY)

  # We use two pointers over heaters
  lheater, rheater = 0, 1

  max_dist = 0
  houses.sort.each do |house|
    while house > heaters[rheater]
      lheater += 1
      rheater += 1
    end

    ldist = house - heaters[lheater]
    rdist = heaters[rheater] - house

    max_dist = [max_dist, [ldist, rdist].min].max
  end

  max_dist
end
