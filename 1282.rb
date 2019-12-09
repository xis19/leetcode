def group_the_people(group_sizes)
  groups = Hash.new { |h, k| h[k] = [] }
  group_sizes.map.with_index { |group_size, index| groups[group_size].push(index) }
  groups.map do |k, v|
    (0...v.length).step(k).map do |index|
      v[index...index + k]
    end.to_a
  end.to_a.flatten(1)
end
