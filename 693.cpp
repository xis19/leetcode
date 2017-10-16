bool hasAlternatingBits(int n) {
    int lastBit = n & 1;
    while(n) {
        if (lastBit != (n & 1)) {
            return false;
        }
        n >>= 1;
        lastBit = !lastBit;
    }
    return true;
}
