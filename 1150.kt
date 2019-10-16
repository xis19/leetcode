fun isMajorityElement(nums: IntArray, target: Int): Boolean {
    var v: Int? = null
    var c: Int = 0
    var maxV: Int? = null
    var maxC: Int = 0
    for (num in nums) {
        if (num != v) {
            if (c > maxC) {
                maxC = c
                maxV = v
            }
            c = 0
            v = num
        }
        ++c
    }
    // Note the last step!
    if (c > maxC) {
        maxV = v
        maxC = c
    }
    return maxV == target && maxC > nums.size / 2
}
