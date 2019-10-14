fun pancakeSort(A: IntArray): List<Int> {
    // One could always find the biggest number, pancake it to the beginning
    // of the line and then pancake the whole range to put the number to the
    // back.
    val steps: MutableList<Int> = arrayListOf()

    fun flip(index: Int) {
        for(i in 0..(index / 2)) {
            val tmp = A[i]
            A[i] = A[index - i]
            A[index - i] = tmp;
        }
    }

    for (i in A.size downTo 1) {
        val iIndex = A.indexOf(i)
        if (iIndex + 1 != i) {
            // This number has to be flipped

            if (iIndex > 0) {
                steps.add(iIndex + 1);
                flip(iIndex)
            }

            steps.add(i)
            flip(i - 1)
        }
    }

    return steps
}

fun main() {
    val a: IntArray = intArrayOf(3, 2, 4, 1)
    val result = pancakeSort(a)
    println(result)
}
