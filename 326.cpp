// NOTE: negative values and zero!!
bool isPowerOfThreeSlow(int n) {
    if (n == 0) return false;
    while(!(n % 3)) {
        n /= 3;
    }
    return n == 1;
}

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    return 1162261467 % n == 0;
}
