int findNthDigit(int n) {
    // Each block of numbers:
    //  1..9 -- 9
    //  10..99 -- 90 * 2
    //  100..999 -- 900 * 3
    //  ...
    if (n <= 9) return n;

    // Note the region and start may overflow
    int length = 1;
    long start = 1;
    while(n > 9 * length * start) {
        n -= 9 * length * start;
        ++length;
        start *= 10;
    }

    // Now we have the numbers, e.g.
    // 100 101 102 103 ...
    // We need to first locate the number n belongs to
    int index = start + (n - 1) / length;
    // We then need to know which digit we need
    // 210 210 210 210 ...
    int offset = (length - n % length);
    if (offset == 0) offset = length;
    // And locate the digit
    for(int i = 0; i < offset; ++i, index /= 10);
    return index % 10;
}

