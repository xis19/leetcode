def coin_change(coins, amount)
  history = [0]
  (1..amount).each do |value|
    if coins.include?(value)
      history.push(1)
    else
      minimal = -1
      coins.each do |coin_value|
        diff = value - coin_value
        next if diff < 0 || history[diff] < 0
        if minimal < 0
          minimal = history[diff] + 1
        else
          minimal = [history[diff] + 1, minimal].min
        end
      end
      history.push(minimal)
    end
  end
  history.last
end
