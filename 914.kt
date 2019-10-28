fun hasGroupsSizeX(deck: IntArray): Boolean {
    // GCD for number of each kind of cards .leq. 1
    var cardCount = mutableMapOf<Int, Int>()
    for (card in deck) {
        if (!cardCount.contains(card)) cardCount[card] = 0
        cardCount.set(card, cardCount[card]!! + 1)
    }

    var countSet = cardCount.values.toList()
    // Calculate GCD
    fun gcd(_x: Int, _y: Int): Int {
        var x = _x
        var y = _y
        while (y != 0) {
            val tmp = x % y
            x = y
            y = tmp
        }
        return x
    }

    var gcdAll = countSet[0]
    for (v in countSet) {
        gcdAll = gcd(v, gcdAll)
    }

    return gcdAll > 1
}
