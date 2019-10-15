import java.util.Random

class Solution {
    private var radius: Double = 0.0
    private var x_center: Double = 0.0
    private var y_center: Double = 0.0

    private var radius2: Double = 0.0
    private var x_start: Double = 0.0
    private var y_start: Double = 0.0

    constructor(radius: Double, x_center: Double, y_center: Double) {
        this.radius = radius
        this.x_center = x_center
        this.y_center = y_center

        radius2 = radius * radius
        x_start = x_center - radius
        y_start = y_center - radius
    }

    fun randPoint(): DoubleArray {
        val random: Random = Random()
        var x: Double = 0.0
        var y: Double = 0.0
        do {
            x = x_start + random.nextDouble() * 2 * radius
            y = y_start + random.nextDouble() * 2 * radius
        } while ((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) > radius2)
        return doubleArrayOf(x, y)
    }
}
