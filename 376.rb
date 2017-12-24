# This is the DP solution, O(n ^ 2)
def wiggle_max_length(nums)
  # For each number, we find the number bigger/smaller than itself before it
  dp_less = [1] * nums.length
  dp_more = [1] * nums.length
  max_len = 0
  nums.each.with_index do |n, i|
    (0...i).reverse_each do |rev_i|
      num = nums[rev_i]
      dp_less[i] = [dp_less[i], dp_more[rev_i] + 1].max if num > n
      dp_more[i] = [dp_more[i], dp_less[rev_i] + 1].max if num < n
    end
    max_len = [dp_less[i], dp_more[i], max_len].max
  end
  max_len
end
