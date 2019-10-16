fun numPrimeArrangements(n: Int): Int {
    val modulus: Long = 1000000000 + 7
    fun primes(): List<Int> {
        var primeList: MutableList<Int> = ArrayList<Int>()
        for (i in 2..n) {
            var isPrime: Boolean = true
            for (j in primeList) {
                if (i % j == 0) {
                    isPrime = false
                    break
                }
            }
            if (isPrime) {
                primeList.add(i)
            }
        }
        return primeList
    }

    fun modulusProduct(a: Long, b: Long): Long {
        return ((a % modulus) * (b % modulus)) % modulus
    }

    val numPrimes: Long = primes().size.toLong()
    val remainder: Long = n.toLong() - numPrimes

    var result: Long = 1
    for (i in 1..remainder) {
        result = modulusProduct(result, i)
    }
    for (i in 1..numPrimes) {
        result = modulusProduct(result, i)
    }

    return result.toInt()
}
