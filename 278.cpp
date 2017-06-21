bool isBadVersion(int);

int firstBadVersion(int n) {
    int l = 1;
    int r = n;

    // Use l + (r - l) / 2 will be better, since l + r might cause overflow
    int m = l + (r - l) / 2;
    while(l != r) {
        if (isBadVersion(m)) {
            r = m;
        } else {
            l = m + 1;
        }
        m = l + (r - l) / 2;
    }

    return l;
}
