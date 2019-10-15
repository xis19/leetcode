fun dayOfYear(date: String): Int {
    val year: Int = date.substring(0..3).toInt()
    val month: Int = date.substring(5..6).toInt()
    val day: Int = date.substring(8..9).toInt()

    val monthDays: IntArray = intArrayOf(
        0,
        31,
        28 + (if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 1 else 0),
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    )

    var monthDay: Int = 0
    for (x in 0..month - 1) {
        monthDay += monthDays[x]
    }
    return monthDay + day
}
