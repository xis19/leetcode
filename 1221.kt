fun balancedStringSplit(s: String): Int {
    var rCount = 0
    var lCount = 0
    var result = 0

    for (ch in s.toCharArray()) {
        when (ch) {
            'R' -> ++rCount
            'L' -> ++lCount
        }
        if (rCount == lCount && rCount > 0) {
            ++result
            rCount = 0
            lCount = 0
        }
    }

    return result
}
