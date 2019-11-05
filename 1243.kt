fun transformArray(arr: IntArray): List<Int> {
    val LEN = arr.size
    var a1: MutableList<Int> = arr.toMutableList()
    var a2: MutableList<Int> = arr.toMutableList()
    var changed = true

    while (changed) {
        changed = false
        for (i in 1..LEN - 2) {
            if (a1[i - 1] > a1[i] && a1[i] < a1[i + 1]) {
                ++a2[i]
                changed = true
            }
            if (a1[i - 1] < a1[i] && a1[i] > a1[i + 1]) {
                --a2[i]
                changed = true
            }
        }

        a1 = a2.toMutableList()
    }

    return a2
}
