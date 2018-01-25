def next_permutation(list)
  return list if list.length <= 1

  l = list.dup
  # Find the first element, from right to left, that is larger than
  # any element on the rhs but less than any element than the lhs
  riter = l.length - 1
  while riter > 0
    if l[riter - 1] < l[riter]
      break
    else
      riter -= 1
    end
  end

  if riter == 0
    # The list is already sorted in descending order, reverse it
    return list.reverse
  end

  new_item = l[riter - 1]

  # Now find the smallest element that is larger than new_item,  from right to
  # left
  rriter = l.length - 1
  while rriter > riter
    break if l[rriter] > new_item
    rriter -= 1
  end

  l[rriter], l[riter - 1] = l[riter - 1], l[rriter]
  l = l[0...riter] + l[riter..-1].reverse

  l
end


def permute(nums)
  result = [nums.dup]
  nums = next_permutation(nums)
  while nums != result.first
    result.push(nums)
    nums = next_permutation(nums)
  end

  result
end
