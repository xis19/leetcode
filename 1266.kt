fun minTimeToVisitAllPoints(points: Array<IntArray>): Int {
    val LEN = points.size
    if (LEN < 2) {
        return 0
    }

    var lastPoint = points[0]
    var steps = 0
    for(i in 1..LEN - 1) {
        val currPoint = points[i]
        val dx = Math.abs(currPoint[0] - lastPoint[0])
        val dy = Math.abs(currPoint[1] - lastPoint[1])
        steps += Math.min(dx, dy) + Math.abs(dx - dy)
        lastPoint = currPoint
    }

    return steps
}
