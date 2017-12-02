def asteroid_collision(asteroids)
  result = []

  asteroids.each do |asteroid|
    if asteroid > 0 || result.empty?
      result.push(asteroid)
      next
    end

    while !result.empty? && result.last > 0 && result.last < asteroid.abs
      result.pop
    end

    # The new asteroid 
    if result.empty? || result.last < 0
      result.push(asteroid)
      next
    end

    if result.last > asteroid.abs
      # The new asteroid disappear
      ;
    elsif result.last == asteroid.abs
      # They vanish
      result.pop
    else
      result.push(asteroid)
    end
  end

  result
end
