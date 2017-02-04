int findComplement(int num) {
    int zeros(0);
    for(; zeros < 32; ++zeros) {
        if (num & (1 << 31)) {
            break;
        }
        num <<= 1;
    }
    num = ~num;
    for(; zeros > 0; --zeros) {
        num >>= 1;
    }

    return num;
}
