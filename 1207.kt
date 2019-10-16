fun uniqueOccurrences(arr: IntArray): Boolean {
    return !arr.groupBy { it }.values.map { it.size }.groupBy { it }.values.map { it.size }.any { it > 1 }
}
