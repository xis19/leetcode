import java.util.Random

class Solution(rects: Array<IntArray>) {
    private val rects = rects
    private val random: Random = Random()
    private var areaProportion: MutableList<Double> = mutableListOf<Double>()

    init {
        // Calculat number of points in an rect
        val points = rects.map { (it[2] - it[0] + 1) * (it[3] - it[1] + 1) }
        val totalPoints = points.sum()
        var s: Double = 0.0
        for (i in points) {
            s += i.toDouble() / totalPoints.toDouble()
            areaProportion.add(s)
        }
    }

    fun pick(): IntArray {
        val rectPicker: Double = random.nextDouble()
        val rectIndex: Int = areaProportion.indexOfFirst { rectPicker < it }
        val (x0, y0, x1, y1) = rects[rectIndex]
        val xxIndex: Int = (x0 + (random.nextDouble() * (x1 - x0 + 1).toDouble()).toInt())
        val yyIndex: Int = (y0 + (random.nextDouble() * (y1 - y0 + 1).toDouble()).toInt())

        return intArrayOf(xxIndex, yyIndex)
    }
}
