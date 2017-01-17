int hammingDistance(int x, int y) {
    int v = x ^ y;
    int nbits(0);
    while(v) {
        if (v & 1) {
            ++nbits;
        }
        v >>= 1;
    }
    return nbits;
}
