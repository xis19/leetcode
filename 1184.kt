fun distanceBetweenBusStops(distance: IntArray, start: Int, destination: Int): Int {
    var s = start
    var d = destination
    if (start > destination) {
        val tmp = d
        d = s
        s = tmp
    }

    var sTd = 0
    for (i in s..d - 1) {
        sTd += distance[i]
    }

    var dTs = 0
    for (i in d..distance.size - 1) {
        dTs += distance[i]
    }
    for (i in 0..s - 1) {
        dTs += distance[i]
    }

    return intArrayOf(sTd, dTs).min()!!
}
