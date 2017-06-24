bool isPerfectSquare(int num) {
    if (num < 0) return false;

    // assume int is 32 bit.
    auto determineHi = [](int num) -> int {
        // sqrt(2 ^ 31) == 46340.95001...
        if (num > 46340) {
            return 46340;
        }
        return num / 2;
    };

    int lo = 0, hi = determineHi(num);
    int mid = lo + (hi - lo) / 2;

    while(hi - lo > 1) {
        auto p = mid * mid;
        if (p > num) {
            hi = mid;
        } else if (p < num) {
            lo = mid + 1;
        } else {
            return true;
        }
        mid = lo + (hi - lo) / 2;
    }
    return hi * hi == num || lo * lo == num;
}
