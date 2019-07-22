def high_five(items)
  items
    .group_by(&:first)
    .map { |k, a| [k, a.map(&:last).sort.reverse.to_a[0...5]] }
    .map { |k, a| [k, ((a.reduce(:+).to_f + 0.5) / 5).to_i] }
end
