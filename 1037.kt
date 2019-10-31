fun isBoomerang(points: Array<IntArray>): Boolean {
    // Use Heron's equation --
    //  A = \frac{1}{4}\sqrt{(a^2 + b^2 + c^2)^2 - 2 * (a^4 + b^4 + c^4)}
    //  A = \frac{1}{4}\sqrt{4(a^2b^2 + a^2c^2 + b^2c^2) - (a^2 + b^2 + c^2)^2}
    fun square(a: Int): Int = a * a

    val a2 = square(points[0][0] - points[1][0]) + square(points[0][1] - points[1][1])
    val b2 = square(points[0][0] - points[2][0]) + square(points[0][1] - points[2][1])
    val c2 = square(points[1][0] - points[2][0]) + square(points[1][1] - points[2][1])

    return square(a2 + b2 + c2) - 2 * (square(a2) + square(b2) + square(c2)) != 0
}
