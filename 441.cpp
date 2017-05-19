int arrangeCoins(int n) {
    int i = 1;
    int j = 0;
    while(n >= i) {
        n -= i;
        ++j, ++i;
    }
    return j;
}
