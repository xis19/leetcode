fun checkPossibility(nums: IntArray): Boolean {
    // Seems easy, but there are many subtle issues..

    // Samples:
    //  [1, 4, 2, 3]    -- remove 4 will connect 1 and 2
    //  [1, -1, 2, 3]   -- remove -1 will connect 1 and 2
    // yet...
    //  [1, -1, 0, 1]   -- you have to remove the leading 1
    // and...
    //  [0, 1, -1, 0, 1]    -- won't have a non-decreasing array!

    val LEN = nums.size
    var indexNonDown: Int? = null
    var last = nums[0]
    for (i in 1..LEN - 1) {
        if (nums[i] < last) {
            if (indexNonDown != null) {
                // Two gaps, fail!
                return false
            }
            indexNonDown = i
        }
        last = nums[i]
    }

    if (indexNonDown == null) {
        return true
    }

    // Now we do a bunch of check...
    if (indexNonDown == 1 || indexNonDown == LEN - 1) {
        // We can always drop the 1st element or last element
        return true
    }

    if (nums[indexNonDown - 2] <= nums[indexNonDown] ||
            nums[indexNonDown - 1] <= nums[indexNonDown + 1]) {
        return true
    }

    return false
}
