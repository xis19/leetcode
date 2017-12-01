require 'set'


def top_k_frequent(nums, k)
  num_count = Hash.new { |hash, v| hash[v] = 0 }
  count_num = []
  nums.each do |num|
    c = num_count[num]

    count_num[c] = Set.new if c >= count_num.length
    count_num[c].delete?(num)

    num_count[num] += 1

    count_num[c + 1] = Set.new if c + 1 >= count_num.length
    count_num[c + 1].add(num)
  end


  top_k = []
  count_num.reverse.each do |s|
    s.each do |i|
      top_k.push(i)
      return top_k if top_k.length == k
    end
  end
end
