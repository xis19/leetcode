def relative_sort_array(arr1, arr2)
  h = Hash.new { |h, k| h[k] = 0 }
  r = Array.new

  arr1.each do |i|
    if arr2.include?(i)
      h[i] += 1
    else
      r.push(i)
    end
  end

  arr2.map { |i| [i] * h[i] }.to_a.flatten + r.sort
end
