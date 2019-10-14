fun updateBoard(board: Array<CharArray>, click: IntArray): Array<CharArray> {
    val ROWS = board.size
    if (ROWS == 0) { return board }
    val COLS = board[0].size
    if (COLS == 0) { return board }

    val DIRS: Array<IntArray> = arrayOf(
        intArrayOf(-1, -1),
        intArrayOf(-1, 0),
        intArrayOf(-1, 1),
        intArrayOf(0, -1),
        intArrayOf(0, 1),
        intArrayOf(1, -1),
        intArrayOf(1, 0),
        intArrayOf(1, 1)
    )

    val (R, C) = click;

    if (board[R][C] == 'M') {
        board[R][C] = 'X'
        return board
    }

    var unrevealedPositions: MutableList<IntArray> = mutableListOf()
    unrevealedPositions.add(click)

    // We need to use a Set to prevent revisiting a certain place multiple times
    // Note MutableSet<IntArray> is not comparing values
    var hash: (IntArray) -> Int = { x -> x[0] * 1000 + x[1] }
    var plannedSites: MutableSet<Int> = mutableSetOf()
    plannedSites.add(hash(click))

    while (!unrevealedPositions.isEmpty()) {
        val (r, c) = unrevealedPositions.removeAt(0)

        var numMines: Int = 0
        var adjacents: MutableList<IntArray> = mutableListOf()
        for ((y, x) in DIRS) {
            val rr = r + y
            val cc = c + x
            if (rr < 0 || rr >= ROWS) continue
            if (cc < 0 || cc >= COLS) continue

            val v = board[rr][cc]
            when(v) {
                'E' -> adjacents.add(intArrayOf(rr, cc))
                'M' -> ++numMines
            }
        }
        if (numMines == 0) {
            board[r][c] = 'B'
            for (pos in adjacents) {
                val h = hash(pos)
                if (!plannedSites.contains(h)) {
                    plannedSites.add(h)
                    unrevealedPositions.add(pos)
                }
            }
        } else {
            board[r][c] = numMines.toString()[0]
        }
    }

    return board
}
