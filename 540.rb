def single_non_duplicate(nums)
  len = nums.length
  return nums[0] if len == 1

  l = 0
  r = len - 1
  while l < r
    mid = l + (r - l) / 2

    if mid == 0
      return nums[0]
    else
      if mid % 2 == 1
        if nums[mid] == nums[mid - 1]
          # the unique number is on the right side
          l = mid + 1
        elsif nums[mid] == nums[mid + 1]
          # the unique number is on the left side
          r = mid - 1
        else
          return nums[mid]
        end
      elsif mid % 2 == 0
        if nums[mid] == nums[mid - 1]
          r = mid - 2
        elsif nums[mid] == nums[mid + 1]
          l = mid + 2
        else
          return nums[mid]
        end
      end
    end
  end

  nums[l]
end


puts single_non_duplicate([1,1,2,2,3,3,4])
puts single_non_duplicate([1,1,2,3,3,4,4])
puts single_non_duplicate([1,2,2,3,3,4,4])
puts single_non_duplicate([1,1,2,2,3,4,4])
