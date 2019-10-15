fun maxNumberOfBalloons(text: String): Int {
    var map = mutableMapOf<Char, Int>(
        'b' to 0,
        'a' to 0,
        'l' to 0,
        'o' to 0,
        'n' to 0
    )

    for (ch in text.toCharArray()) {
        map.computeIfPresent(ch) { _, v -> v + 1 }
    }

    var result: Int = 0
    while (true) {
        map.computeIfPresent('b') { _, v -> v - 1 }
        map.computeIfPresent('a') { _, v -> v - 1 }
        map.computeIfPresent('l') { _, v -> v - 2 }
        map.computeIfPresent('o') { _, v -> v - 2 }
        map.computeIfPresent('n') { _, v -> v - 1 }

        if (map.values.any { it < 0 }) {
            break
        }
        ++result
    }
    return result
}
