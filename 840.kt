fun numMagicSquaresInside(grid: Array<IntArray>): Int {
    val expectedNumbers = setOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    // 5 must be at the center of the square
    fun find5(): List<IntArray> {
        // Note 5 cannot be at boundary
        val result = ArrayList<IntArray>()
        for (y in 1..grid.size - 2) {
            for (x in 1..grid[0].size - 2) {
                if (grid[y][x] == 5) {
                    result.add(intArrayOf(y, x))
                }
            }
        }
        return result
    }

    fun verifySquare(cY: Int, cX: Int): Boolean {
        val r0 = grid[cY - 1][cX - 1] + grid[cY - 1][cX] + grid[cY - 1][cX + 1]
        val r1 = grid[cY][cX - 1] + grid[cY][cX] + grid[cY][cX + 1]
        val r2 = grid[cY + 1][cX - 1] + grid[cY + 1][cX] + grid[cY + 1][cX + 1]

        val c0 = grid[cY - 1][cX - 1] + grid[cY][cX - 1] + grid[cY + 1][cX - 1]
        val c1 = grid[cY - 1][cX] + grid[cY][cX] + grid[cY + 1][cX]
        val c2 = grid[cY - 1][cX + 1] + grid[cY][cX + 1] + grid[cY + 1][cX + 1]

        val diag1 = grid[cY - 1][cX - 1] + grid[cY][cX] + grid[cY + 1][cX + 1]
        val diag2 = grid[cY + 1][cX - 1] + grid[cY][cX] + grid[cY - 1][cX + 1]

        val numbers = setOf(
            grid[cY - 1][cX - 1], grid[cY - 1][cX], grid[cY - 1][cX + 1],
            grid[cY][cX - 1], grid[cY][cX], grid[cY][cX + 1],
            grid[cY + 1][cX - 1], grid[cY + 1][cX], grid[cY + 1][cX + 1]
        )

        return (intArrayOf(r0, r1, r2, c0, c1, c2, diag1, diag2).groupBy { it }.size == 1 &&
                expectedNumbers == numbers)
    }

    return find5().count { verifySquare(it[0], it[1]) }
}
