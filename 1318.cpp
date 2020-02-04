int minFlips(int a, int b, int c) {
    int numFlips = 0;
    while (c > 0 || (a | b) > 0) {
        int a1 = a & 1, b1 = b & 1, c1 = c & 1;
        if (c1 == 0) {
            numFlips += a1 + b1;
        } else {
            numFlips += !(a1 + b1);
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return numFlips;
}
