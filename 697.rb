def find_shortest_sub_array(nums)
  record = Hash.new do |hsh, v|
    hsh[v] = {
      count: 0,
      first: 999999,
      last: 0
    }
  end

  nums.each_with_index do |v, i|
    record[v][:count] += 1
    record[v][:first] = [i, record[v][:first]].min
    record[v][:last] = i
  end

  max_count = 0
  min_len = 9999999

  record.each do |_, v|
    if v[:count] > max_count
      max_count = v[:count]
      min_len = v[:last] - v[:first] + 1
    elsif v[:count] == max_count
      min_len = [min_len, v[:last] - v[:first] + 1].min
    end
  end

  min_len
end
