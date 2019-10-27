fun queensAttacktheKing(queens: Array<IntArray>, king: IntArray): List<List<Int>> {
    // The king will find any queen that could attack it, first at each
    // direction

    val DIRS = listOf(
        intArrayOf(-1, 0),
        intArrayOf(-1, 1),
        intArrayOf(0, 1),
        intArrayOf(1, 1),
        intArrayOf(1, 0),
        intArrayOf(1, -1),
        intArrayOf(0, -1),
        intArrayOf(-1, -1)
    )

    var result = mutableListOf<List<Int>>()
    for (dir in DIRS) {
        var queenPos = king.toMutableList()
        queenPos[0] += dir[0]
        queenPos[1] += dir[1]

        while(
            queenPos[0] >= 0 && queenPos[0] <= 7 &&
            queenPos[1] >= 0 && queenPos[1] <= 7
        ) {
            val pos = queens.indexOfFirst { it[0] == queenPos[0] && it[1] == queenPos[1] }
            if (pos != -1) {
                result.add(listOf(queens[pos][0], queens[pos][1]))
                break
            }

            queenPos[0] += dir[0]
            queenPos[1] += dir[1]
        }
    }

    return result
}
