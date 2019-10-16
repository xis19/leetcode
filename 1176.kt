fun dietPlanPerformance(calories: IntArray, k: Int, lower: Int, upper: Int): Int {
    var points = 0
    var c = 0

    for (i in 0..k - 2) {
        c += calories[i]
    }

    for (i in k - 1..calories.size - 1) {
        c += calories[i]

        if (c < lower) {
            --points
        } else if (c > upper) {
            ++points
        }

        c -= calories[i - k + 1]
    }

    return points
}
