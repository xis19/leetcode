int bitwiseComplement(int N) {
    const int NBITS = sizeof(int) * 8;
    const unsigned int HIGHEST_MASK = 1 << (NBITS - 1);

    if (N == 0) {
        return 1;
    }

    int shift = 0;
    unsigned int v = N;
    while((HIGHEST_MASK & v) == 0) {
        v <<= 1;
        ++shift;
    }

    v = ~v;
    v >>= shift;
    return static_cast<int>(v);
}
